%{

/*
parser.y - yacc source for the MiniC
Programmer : (3Á¶) 1615011 ±èÁö¹Î, 1615017 ¹Ú»ó¾Æ, 1615019 ¹Ú¼öºó
Program : °úÁ¦3 Parser
Date : 2019/06/03
*/

#pragma warning(disable : 4996)
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

int t_int=0;
int t_void=0;
int t_float=0;
int t_char=0;

void printLine(int line_num);
extern void printError2(ERR e);
extern yylex();
extern yyerror(s);

%}


%token TIDENT TILLIDENT1 TILLIDENT2 TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE TEIF TFLOAT TCHAR
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TINC TDEC TLESS TGREAT TNUM
%token TSTRCONST TRNUMBER TADD TMINUS TSTAR TDIV TMOD TASSIGN TNOT TSMALL TBIG TSMALLLEFT TSMALLRIGHT TMIDLEFT TMIDRIGHT TBIGLEFT TBIGRIGHT TCOMMA TSEMI TERROR TOVERST

%right TASSIGN
%left TADD TMINUS
%left TSTAR TDIV TMOD

%%
mini_c 			: translation_unit 
			;
			
translation_unit 		: external_dcl				
			| translation_unit external_dcl 	
			;
	
external_dcl 		: function_def			
		  	| declaration			
			| TIDENT TSEMI			
			| TIDENT error
			{ 
				yyerrok;  
				printError2(WRONGST);
			}
			;
				
function_def 		: function_header compound_st 
			| function_header TSEMI	
			| function_header error		
			{  	
				current_tmp->type=0; 
				yyerrok;  
				printError2(WRONGFUNC);
			}
			;
		
function_header 		: dcl_spec function_name formal_param 
			;
	
dcl_spec 			: dcl_specifiers
			;
			
dcl_specifiers 		: dcl_specifier			
		 	| dcl_specifiers dcl_specifier	
			;
	
dcl_specifier 		: type_qualifier				
			| type_specifier	
			;
			
type_qualifier 		: TCONST		
			;
			
type_specifier 		: TINT		{ t_int=1; }				
		 	| TVOID		{ t_void=1; }
			| TCHAR		{ t_char=1; }
			| TFLOAT		{ t_float=1;}
			;
			
function_name 		: TIDENT
			{	
				
				if(current_id -> type == 0 || current_id->type ==13 )
				{	
					if(t_int ==1 ) current_id->type = 10;
					else if(t_void == 1) current_id->type = 9;
					else if(t_char ==1) current_id->type =12;
					else if(t_float==1) current_id->type =11;
					
					t_int =0;
					t_void =0;
					t_char =0;
					t_float=0;
					
					current_tmp = current_id;
				}	
			}
			| 
			{ 
				yyerrok; 
				printError2(NOFUNCNAME); 
			}
			;
				
formal_param 		: TSMALLLEFT opt_formal_param TSMALLRIGHT 
			;
		
opt_formal_param 		: formal_param_list		
		   	|			
			;
					
formal_param_list 		: param_dcl							
		    	| formal_param_list TCOMMA param_dcl
			| formal_param_list param_dcl 
			{
				yyerrok;  
				printError2(NOCOMMA);
			}	
			;
	
param_dcl 		: dcl_spec declarator			
			;
			
compound_st 		: TMIDLEFT compound TMIDRIGHT	
			| TMIDLEFT compound error		
			{ 
				yyerrok; 
				printError2(NOBRACE);
			}
			;

compound		: opt_dcl_list opt_stat_list	
			;
	
opt_dcl_list 		: declaration_list			
			|				
			;
					
declaration_list 		: declaration			
			| declaration_list declaration		
			;
 		
declaration 		: dcl_spec init_dcl_list TSEMI
			{	
				
				t_int=0;
				t_void=0;
				t_char=0;
				t_float=0;
			}
			| dcl_spec init_dcl_list error
			{	
				
				current_tmp->type = 0;
				yyerrok;

				t_int=0;
				t_void=0;
				t_char=0;
				t_float=0;

				printError2(NOSEMI);
			}
			;
		
init_dcl_list 		: init_declarator			
			| init_dcl_list TCOMMA init_declarator
			| 
			{ 
				yyerrok; 
				printError2(WRONGDEC); 
			}
			;
	
init_declarator 		: declarator					
		 	| declarator TASSIGN TNUMBER
			| declarator TASSIGN TMINUS TNUMBER			
		 	| declarator TASSIGN TRNUMBER	
		 	| declarator TASSIGN TMINUS TRNUMBER
			| declarator TASSIGN TSTRCONST		

			;
		
declarator 		: TIDENT
			{	
				
				if(current_id->type == 0)
				{
					if(t_int ==1 ) current_id->type = 2;
					else if(t_void == 1) current_id->type = 1;
					else if(t_char ==1) current_id->type =4;
					else if(t_float==1) current_id->type =3;

				}
				current_tmp=current_id;
			}						
	     		| TIDENT TBIGLEFT opt_number TBIGRIGHT
			{	
				
				if(current_id->type == 0)
				{
					if(t_int ==1 ) current_id->type = 6;
					else if(t_void == 1) current_id->type = 5;
					else if(t_char ==1) current_id->type =8;
					else if(t_float==1) current_id->type =7;
				}
				current_tmp=current_id;
			}
			| TIDENT TBIGLEFT opt_number error
			{	
				
				yyerrok;
				printError2(NOBRACKET);
			}

			;
		
opt_number 		: TNUMBER		
	     		|			
			;
					
opt_stat_list 		: statement_list		
		 	|			
			;
					
statement_list 		: statement			
		 	| statement_list statement	
			| statement_list declaration	
			;
 		
statement 		: compound_st			
	   		| expression_st			
	   		| if_st				
	   		| while_st				
	   		| return_st			
	   		;

expression_st 		: opt_expression TSEMI	
			| expression error	
			{	

				yyerrok;
				printError2(NOSEMI);
			}
			;
			
opt_expression 		: expression					
		 	|			
			;
					
if_st 			: TIF TSMALLLEFT expression TSMALLRIGHT statement TEIF			
			| TIF TSMALLLEFT expression TSMALLRIGHT statement TELSE statement TEIF
			;

while_st 			: TWHILE TSMALLLEFT expression TSMALLRIGHT statement
			;
 
return_st 			: TRETURN opt_expression TSEMI
			;
		
expression 		: assignment_exp	
			;
			
assignment_exp 		: logical_or_exp
						
			| unary_exp1 TASSIGN assignment_exp 		
			| unary_exp1 TADDASSIGN assignment_exp	
			| unary_exp1 TSUBASSIGN assignment_exp 		
			| unary_exp1 TMULASSIGN assignment_exp 	
			| unary_exp1 TDIVASSIGN assignment_exp 		
			| unary_exp1 TMODASSIGN assignment_exp 
			| unary_exp2 TASSIGN assignment_exp
			{
				yyerrok; 
				printError2(INVALIDASSIGN);
			}
			| unary_exp2 TADDASSIGN assignment_exp
			{
				yyerrok; 
				printError2(INVALIDASSIGN);
			}
			| unary_exp2 TSUBASSIGN assignment_exp
			{
				yyerrok; 
				printError2(INVALIDASSIGN);
			}
			| unary_exp2 TMULASSIGN assignment_exp
			{
				yyerrok; 
				printError2(INVALIDASSIGN);
			}
			| unary_exp2 TDIVASSIGN assignment_exp
			{
				yyerrok; 
				printError2(INVALIDASSIGN);
			}
			| unary_exp2 TMODASSIGN assignment_exp
			{
				yyerrok; 
				printError2(INVALIDASSIGN);
			}
			;

logical_or_exp 		: logical_and_exp				
			| logical_or_exp TOR logical_and_exp		
			;
	
logical_and_exp 		: equality_exp						
		 	| logical_and_exp TAND equality_exp		
			;

equality_exp 		: relational_exp				
			| equality_exp TEQUAL relational_exp 		
			| equality_exp TNOTEQU relational_exp 	
			;
	
relational_exp 		: additive_exp 				
			| relational_exp TBIG additive_exp 		
			| relational_exp TSMALL additive_exp 		
			| relational_exp TGREAT additive_exp 		
			| relational_exp TLESS additive_exp 		
			;
 	
additive_exp 		: multiplicative_exp				
			| additive_exp TADD multiplicative_exp 	
			| additive_exp TMINUS multiplicative_exp 	
			;
 	
multiplicative_exp 		: unary_exp1					
		    	| multiplicative_exp TSTAR unary_exp1 		
		    	| multiplicative_exp TDIV unary_exp1 		
		    	| multiplicative_exp TMOD unary_exp1
			| unary_exp2					
		    	| multiplicative_exp TSTAR unary_exp2 		
		    	| multiplicative_exp TDIV unary_exp2 		
		    	| multiplicative_exp TMOD unary_exp2		
			;
 	
unary_exp1 		: postfix_exp					
	   		| TMINUS unary_exp1		
	   		| TNOT unary_exp1				
	   		| TINC unary_exp1				
	   		| TDEC unary_exp1				
			;

unary_exp2 		: primary_exp2					
	   		| TMINUS unary_exp2									
			;


			
postfix_exp 		: primary_exp					
	      		| postfix_exp TBIGLEFT expression TBIGRIGHT 
	      		| postfix_exp TSMALLLEFT opt_actual_param TSMALLRIGHT 
	      		| postfix_exp TINC				
	      		| postfix_exp TDEC
			| postfix_exp TBIGLEFT expression error
			{		
				yyerrok;
				printError2(NOBRACKET);
			}
				
			;
		
opt_actual_param 		: actual_param						
		  	|					
			;
					
actual_param 		: actual_param_list				
			;
			
actual_param_list 		: assignment_exp				
		   	| actual_param_list TCOMMA assignment_exp	
			;
 	
primary_exp 		: TIDENT
			{	
				if(current_id->type == 0)
				{
					current_id->type=13;
				}
			}
			;

primary_exp2		: TNUMBER			
			| TRNUMBER
			| TSTRCONST					
	     		| TSMALLLEFT expression TSMALLRIGHT	
			;	
		
%%

void printLine(int num){
	printf("\t%d\t", num);
}


