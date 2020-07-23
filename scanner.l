%{

/*
scanner.l - lexical analyzer for the MiniC
Programmer : (3Á¶) 1615011 ±èÁö¹Î, 1615017 ¹Ú»ó¾Æ, 1615019 ¹Ú¼öºó
Program : °úÁ¦3 Parser
Date : 2019/06/03
*/

#pragma warning(disable : 4996)
#include "tn.h"
#include "glob.h"
#include <stdio.h>
#include <stdlib.h>

extern void printtoken(enum tokentypes tn);
extern yyerror(char * s);


%}
%%

"\n"					line_num++;
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(TNUMBER);
[0-9]+[a-zA-Z_]+				{ printtoken(TILLIDENT1); }
"const"					return(TCONST);
"else"					return(TELSE);
"if"					return(TIF);
"endif"					return(TEIF);
"int"					return(TINT);
"float"					return(TFLOAT);
"char"					return(TCHAR);
"return"					return(TRETURN);
"void"					return(TVOID);
"while"					return(TWHILE);
"=="					return(TEQUAL);
"!="					return(TNOTEQU);
"<="					return(TLESS);
">="					return(TGREAT);
"&&"					return(TAND);
"||"					return(TOR);
"++"					return(TINC);
"--"					return(TDEC);
"+="					return(TADDASSIGN);
"-="					return(TSUBASSIGN);
"*="					return(TMULASSIGN);
"/="					return(TDIVASSIGN);
"%="					return(TMODASSIGN);
[A-Za-z_][A-Za-z0-9_]*			{
						if(yyleng > 10){ 
							printtoken(TILLIDENT2); 
						}
						else {
							printtoken(TIDENT); 
							return(TIDENT);
						} 
					}
"//".*					;
[ \t]					;
\"(\\.|[^"\\])*\"			return(TSTRCONST);
[0-9]+"."[0-9]+				return(TRNUMBER);
"+"					return(TADD);
"-"					return(TMINUS);
"*"					return(TSTAR);
"/"					return(TDIV);
"%"					return(TMOD);
"="					return(TASSIGN);
"!"					return(TNOT);
"<"					return(TSMALL);
">"					return(TBIG);
"("					return(TSMALLLEFT);
")"					return(TSMALLRIGHT);
"{"					return(TMIDLEFT);
"}"					return(TMIDRIGHT);
"["					return(TBIGLEFT);
"]"					return(TBIGRIGHT);
","					return(TCOMMA);
";"					return(TSEMI);
.					{ printtoken(TERROR); }

%%

int yywrap()
{
	return 1;
}