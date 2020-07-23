
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TILLIDENT1	259
#define	TILLIDENT2	260
#define	TNUMBER	261
#define	TCONST	262
#define	TELSE	263
#define	TIF	264
#define	TINT	265
#define	TRETURN	266
#define	TVOID	267
#define	TWHILE	268
#define	TEIF	269
#define	TFLOAT	270
#define	TCHAR	271
#define	TADDASSIGN	272
#define	TSUBASSIGN	273
#define	TMULASSIGN	274
#define	TDIVASSIGN	275
#define	TMODASSIGN	276
#define	TOR	277
#define	TAND	278
#define	TEQUAL	279
#define	TNOTEQU	280
#define	TINC	281
#define	TDEC	282
#define	TLESS	283
#define	TGREAT	284
#define	TNUM	285
#define	TSTRCONST	286
#define	TRNUMBER	287
#define	TADD	288
#define	TMINUS	289
#define	TSTAR	290
#define	TDIV	291
#define	TMOD	292
#define	TASSIGN	293
#define	TNOT	294
#define	TSMALL	295
#define	TBIG	296
#define	TSMALLLEFT	297
#define	TSMALLRIGHT	298
#define	TMIDLEFT	299
#define	TMIDRIGHT	300
#define	TBIGLEFT	301
#define	TBIGRIGHT	302
#define	TCOMMA	303
#define	TSEMI	304
#define	TERROR	305
#define	TOVERST	306

#line 1 "parser.y"


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


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		198
#define	YYFLAG		-32768
#define	YYNTBASE	52

#define YYTRANSLATE(x) ((unsigned)(x) <= 306 ? yytranslate[x] : 100)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    51,    53,    54,    58,    60,    61,    63,    67,    70,
    73,    77,    81,    84,    86,    87,    89,    92,    96,   100,
   102,   106,   107,   109,   113,   118,   122,   127,   131,   133,
   138,   143,   145,   146,   148,   149,   151,   154,   157,   159,
   161,   163,   165,   167,   170,   173,   175,   176,   183,   192,
   198,   202,   204,   206,   210,   214,   218,   222,   226,   230,
   234,   238,   242,   246,   250,   254,   256,   260,   262,   266,
   268,   272,   276,   278,   282,   286,   290,   294,   296,   300,
   304,   306,   310,   314,   318,   320,   324,   328,   332,   334,
   337,   340,   343,   346,   348,   351,   353,   358,   363,   366,
   369,   374,   376,   377,   379,   381,   385,   387,   389,   391,
   393
};

static const short yyrhs[] = {    53,
     0,    54,     0,    53,    54,     0,    55,     0,    71,     0,
     3,    49,     0,     3,     1,     0,    56,    67,     0,    56,
    49,     0,    56,     1,     0,    57,    62,    63,     0,    58,
     0,    59,     0,    58,    59,     0,    60,     0,    61,     0,
     7,     0,    10,     0,    12,     0,    16,     0,    15,     0,
     3,     0,     0,    42,    64,    43,     0,    65,     0,     0,
    66,     0,    65,    48,    66,     0,    65,    66,     0,    57,
    74,     0,    44,    68,    45,     0,    44,    68,     1,     0,
    69,    76,     0,    70,     0,     0,    71,     0,    70,    71,
     0,    57,    72,    49,     0,    57,    72,     1,     0,    73,
     0,    72,    48,    73,     0,     0,    74,     0,    74,    38,
     6,     0,    74,    38,    34,     6,     0,    74,    38,    32,
     0,    74,    38,    34,    32,     0,    74,    38,    31,     0,
     3,     0,     3,    46,    75,    47,     0,     3,    46,    75,
     1,     0,     6,     0,     0,    77,     0,     0,    78,     0,
    77,    78,     0,    77,    71,     0,    67,     0,    79,     0,
    81,     0,    82,     0,    83,     0,    80,    49,     0,    84,
     1,     0,    84,     0,     0,     9,    42,    84,    43,    78,
    14,     0,     9,    42,    84,    43,    78,     8,    78,    14,
     0,    13,    42,    84,    43,    78,     0,    11,    80,    49,
     0,    85,     0,    86,     0,    92,    38,    85,     0,    92,
    17,    85,     0,    92,    18,    85,     0,    92,    19,    85,
     0,    92,    20,    85,     0,    92,    21,    85,     0,    93,
    38,    85,     0,    93,    17,    85,     0,    93,    18,    85,
     0,    93,    19,    85,     0,    93,    20,    85,     0,    93,
    21,    85,     0,    87,     0,    86,    22,    87,     0,    88,
     0,    87,    23,    88,     0,    89,     0,    88,    24,    89,
     0,    88,    25,    89,     0,    90,     0,    89,    41,    90,
     0,    89,    40,    90,     0,    89,    29,    90,     0,    89,
    28,    90,     0,    91,     0,    90,    33,    91,     0,    90,
    34,    91,     0,    92,     0,    91,    35,    92,     0,    91,
    36,    92,     0,    91,    37,    92,     0,    93,     0,    91,
    35,    93,     0,    91,    36,    93,     0,    91,    37,    93,
     0,    94,     0,    34,    92,     0,    39,    92,     0,    26,
    92,     0,    27,    92,     0,    99,     0,    34,    93,     0,
    98,     0,    94,    46,    84,    47,     0,    94,    42,    95,
    43,     0,    94,    26,     0,    94,    27,     0,    94,    46,
    84,     1,     0,    96,     0,     0,    97,     0,    85,     0,
    97,    48,    85,     0,     3,     0,     6,     0,    32,     0,
    31,     0,    42,    84,    43,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    39,    42,    43,    46,    47,    48,    49,    56,    57,    58,
    66,    69,    72,    73,    76,    77,    80,    83,    84,    85,
    86,    89,   107,   114,   117,   118,   121,   122,   123,   130,
   133,   134,   141,   144,   145,   148,   149,   152,   160,   175,
   176,   177,   184,   185,   186,   187,   188,   189,   193,   206,
   218,   227,   228,   231,   232,   235,   236,   237,   240,   241,
   242,   243,   244,   247,   248,   256,   257,   260,   261,   264,
   267,   270,   273,   275,   276,   277,   278,   279,   280,   281,
   286,   291,   296,   301,   306,   313,   314,   317,   318,   321,
   322,   323,   326,   327,   328,   329,   330,   333,   334,   335,
   338,   339,   340,   341,   342,   343,   344,   345,   348,   349,
   350,   351,   352,   355,   356,   361,   362,   363,   364,   365,
   366,   374,   375,   378,   381,   382,   385,   394,   395,   396,
   397
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TILLIDENT1","TILLIDENT2","TNUMBER","TCONST","TELSE","TIF","TINT","TRETURN",
"TVOID","TWHILE","TEIF","TFLOAT","TCHAR","TADDASSIGN","TSUBASSIGN","TMULASSIGN",
"TDIVASSIGN","TMODASSIGN","TOR","TAND","TEQUAL","TNOTEQU","TINC","TDEC","TLESS",
"TGREAT","TNUM","TSTRCONST","TRNUMBER","TADD","TMINUS","TSTAR","TDIV","TMOD",
"TASSIGN","TNOT","TSMALL","TBIG","TSMALLLEFT","TSMALLRIGHT","TMIDLEFT","TMIDRIGHT",
"TBIGLEFT","TBIGRIGHT","TCOMMA","TSEMI","TERROR","TOVERST","mini_c","translation_unit",
"external_dcl","function_def","function_header","dcl_spec","dcl_specifiers",
"dcl_specifier","type_qualifier","type_specifier","function_name","formal_param",
"opt_formal_param","formal_param_list","param_dcl","compound_st","compound",
"opt_dcl_list","declaration_list","declaration","init_dcl_list","init_declarator",
"declarator","opt_number","opt_stat_list","statement_list","statement","expression_st",
"opt_expression","if_st","while_st","return_st","expression","assignment_exp",
"logical_or_exp","logical_and_exp","equality_exp","relational_exp","additive_exp",
"multiplicative_exp","unary_exp1","unary_exp2","postfix_exp","opt_actual_param",
"actual_param","actual_param_list","primary_exp","primary_exp2",""
};
#endif

static const short yyr1[] = {     0,
    52,    53,    53,    54,    54,    54,    54,    55,    55,    55,
    56,    57,    58,    58,    59,    59,    60,    61,    61,    61,
    61,    62,    62,    63,    64,    64,    65,    65,    65,    66,
    67,    67,    68,    69,    69,    70,    70,    71,    71,    72,
    72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
    74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
    78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
    83,    84,    85,    85,    85,    85,    85,    85,    85,    85,
    85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
    88,    88,    89,    89,    89,    89,    89,    90,    90,    90,
    91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
    92,    92,    92,    93,    93,    94,    94,    94,    94,    94,
    94,    95,    95,    96,    97,    97,    98,    99,    99,    99,
    99
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     1,     0,     3,     1,     0,     1,     3,     2,     2,
     3,     3,     2,     1,     0,     1,     2,     3,     3,     1,
     3,     0,     1,     3,     4,     3,     4,     3,     1,     4,
     4,     1,     0,     1,     0,     1,     2,     2,     1,     1,
     1,     1,     1,     2,     2,     1,     0,     6,     8,     5,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     1,     3,     3,     3,     1,     2,
     2,     2,     2,     1,     2,     1,     4,     4,     2,     2,
     4,     1,     0,     1,     1,     3,     1,     1,     1,     1,
     3
};

static const short yydefact[] = {     0,
     0,    17,    18,    19,    21,    20,     1,     2,     4,     0,
    42,    12,    13,    15,    16,     5,     7,     6,     3,    10,
    35,     9,     8,    49,     0,     0,    40,    43,    14,    42,
     0,    55,    34,    36,    53,    26,    11,    39,     0,    38,
     0,    49,    32,    31,   127,   128,     0,    67,     0,     0,
     0,   130,   129,     0,     0,     0,    59,    33,    54,    56,
    60,     0,    61,    62,    63,     0,    72,    73,    86,    88,
    90,    93,    98,   101,   105,   109,   116,   114,    37,    52,
     0,     0,     0,    25,    27,    41,    44,    48,    46,     0,
     0,     0,    66,     0,     0,   112,   113,   110,   115,   111,
     0,    58,    57,    64,    65,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   119,   120,   123,     0,    51,    50,    30,    24,     0,    29,
    45,    47,     0,    71,     0,   131,    87,   101,   105,    89,
    91,    92,    97,    96,    95,    94,    99,   100,   102,   106,
   103,   107,   104,   108,    75,    76,    77,    78,    79,    74,
    81,    82,    83,    84,    85,    80,   125,     0,   122,   124,
     0,    28,    67,    67,   118,     0,   121,   117,     0,    70,
   126,    67,    68,     0,    69,     0,     0,     0
};

static const short yydefgoto[] = {   196,
     7,     8,     9,    10,    30,    12,    13,    14,    15,    25,
    37,    83,    84,    85,    57,    31,    32,    33,    16,    26,
    27,    28,    81,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,   178,   179,   180,    77,    78
};

static const short yypact[] = {   234,
     5,-32768,-32768,-32768,-32768,-32768,   234,-32768,-32768,     3,
    38,   193,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   193,-32768,-32768,   -15,     8,    29,-32768,    22,-32768,    43,
    37,   135,   193,-32768,    56,   193,-32768,-32768,    43,-32768,
   149,    17,-32768,-32768,-32768,-32768,    41,   184,    60,   103,
   103,-32768,-32768,   184,   103,   184,-32768,-32768,   101,-32768,
-32768,    54,-32768,-32768,-32768,    10,-32768,    83,    86,    15,
   123,     1,     7,   210,   215,   171,-32768,-32768,-32768,-32768,
     4,    43,    76,   108,-32768,-32768,-32768,-32768,-32768,    23,
   184,    72,-32768,   184,   103,-32768,-32768,-32768,-32768,-32768,
    79,-32768,-32768,-32768,-32768,   184,   184,   184,   184,   184,
   184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
   184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
-32768,-32768,   184,   184,-32768,-32768,-32768,-32768,   193,-32768,
-32768,-32768,    88,-32768,    93,-32768,    86,-32768,-32768,    15,
   123,   123,     1,     1,     1,     1,     7,     7,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   104,-32768,   105,
    32,-32768,   162,   162,-32768,   184,-32768,-32768,    18,-32768,
-32768,   162,-32768,   140,-32768,   170,   172,-32768
};

static const short yypgoto[] = {-32768,
-32768,   142,-32768,-32768,     0,-32768,   164,-32768,-32768,-32768,
-32768,-32768,-32768,   -81,   168,-32768,-32768,-32768,    28,-32768,
   143,   109,-32768,-32768,-32768,   -58,-32768,   137,-32768,-32768,
-32768,   -46,  -105,-32768,    80,    85,   -52,    47,   -29,   -42,
   -17,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		253


static const short yytable[] = {    11,
   103,    93,   140,    20,   135,    17,    11,    96,    97,   101,
   105,    98,   100,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   192,   -22,   177,   141,    38,
    35,   193,   187,   114,   115,    82,    99,    43,   108,   109,
    24,   116,   117,   118,   143,    42,    21,   145,    34,    36,
   136,    22,    98,    18,   142,   151,   152,   182,   -66,    41,
    79,    80,    35,   148,   148,   148,   148,   148,   148,   148,
   148,   148,   148,   159,   161,   163,    39,    40,   188,   -23,
   191,    44,    91,    82,   157,   158,   102,   181,   149,   149,
   149,   149,   149,   149,   149,   149,   149,   149,   160,   162,
   164,    94,   104,    45,   106,    45,    46,     2,   107,    47,
     3,    48,     4,    49,     2,     5,     6,     3,   138,     4,
   144,   146,     5,     6,   189,   190,    50,    51,    50,    51,
   183,    52,    53,   194,    54,   184,    95,    45,    82,    55,
    46,    55,    56,    47,    21,    48,   185,    49,    19,   -67,
   110,   111,   186,   195,    87,   139,   153,   154,   155,   156,
    50,    51,   112,   113,    45,    52,    53,    46,    54,   197,
    47,   198,    48,    55,    49,    29,    56,    23,    21,    88,
    89,    86,    90,   -67,    92,   147,    45,    50,    51,    46,
   137,   150,    52,    53,     0,    54,   131,   132,     0,     2,
    55,     0,     3,    56,     4,    21,     0,     5,     6,    50,
    51,     0,   133,     0,    52,    53,   134,    54,     0,     0,
     0,     0,    55,     0,     0,    56,   119,   120,   121,   122,
   123,   125,   126,   127,   128,   129,     1,     0,     0,     0,
     2,     0,     0,     3,     0,     4,     0,   124,     5,     6,
     0,     0,   130
};

static const short yycheck[] = {     0,
    59,    48,    84,     1,     1,     1,     7,    50,    51,    56,
     1,    54,    55,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,     8,    42,   133,     6,     1,
    46,    14,     1,    33,    34,    36,    54,     1,    24,    25,
     3,    35,    36,    37,    91,     3,    44,    94,    21,    42,
    47,    49,    95,    49,    32,   108,   109,   139,    49,    38,
    33,     6,    46,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,    48,    49,    47,    42,
   186,    45,    42,    84,   114,   115,    59,   134,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,    42,    49,     3,    22,     3,     6,     7,    23,     9,
    10,    11,    12,    13,     7,    15,    16,    10,    43,    12,
    49,    43,    15,    16,   183,   184,    26,    27,    26,    27,
    43,    31,    32,   192,    34,    43,    34,     3,   139,    39,
     6,    39,    42,     9,    44,    11,    43,    13,     7,    49,
    28,    29,    48,    14,     6,    48,   110,   111,   112,   113,
    26,    27,    40,    41,     3,    31,    32,     6,    34,     0,
     9,     0,    11,    39,    13,    12,    42,    10,    44,    31,
    32,    39,    34,    49,    48,   106,     3,    26,    27,     6,
    82,   107,    31,    32,    -1,    34,    26,    27,    -1,     7,
    39,    -1,    10,    42,    12,    44,    -1,    15,    16,    26,
    27,    -1,    42,    -1,    31,    32,    46,    34,    -1,    -1,
    -1,    -1,    39,    -1,    -1,    42,    17,    18,    19,    20,
    21,    17,    18,    19,    20,    21,     3,    -1,    -1,    -1,
     7,    -1,    -1,    10,    -1,    12,    -1,    38,    15,    16,
    -1,    -1,    38
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 50 "parser.y"
{ 
				yyerrok;  
				printError2(WRONGST);
			;
    break;}
case 10:
#line 59 "parser.y"
{  	
				current_tmp->type=0; 
				yyerrok;  
				printError2(WRONGFUNC);
			;
    break;}
case 18:
#line 83 "parser.y"
{ t_int=1; ;
    break;}
case 19:
#line 84 "parser.y"
{ t_void=1; ;
    break;}
case 20:
#line 85 "parser.y"
{ t_char=1; ;
    break;}
case 21:
#line 86 "parser.y"
{ t_float=1;;
    break;}
case 22:
#line 90 "parser.y"
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
			;
    break;}
case 23:
#line 108 "parser.y"
{ 
				yyerrok; 
				printError2(NOFUNCNAME); 
			;
    break;}
case 29:
#line 124 "parser.y"
{
				yyerrok;  
				printError2(NOCOMMA);
			;
    break;}
case 32:
#line 135 "parser.y"
{ 
				yyerrok; 
				printError2(NOBRACE);
			;
    break;}
case 38:
#line 153 "parser.y"
{	
				
				t_int=0;
				t_void=0;
				t_char=0;
				t_float=0;
			;
    break;}
case 39:
#line 161 "parser.y"
{	
				
				current_tmp->type = 0;
				yyerrok;

				t_int=0;
				t_void=0;
				t_char=0;
				t_float=0;

				printError2(NOSEMI);
			;
    break;}
case 42:
#line 178 "parser.y"
{ 
				yyerrok; 
				printError2(WRONGDEC); 
			;
    break;}
case 49:
#line 194 "parser.y"
{	
				
				if(current_id->type == 0)
				{
					if(t_int ==1 ) current_id->type = 2;
					else if(t_void == 1) current_id->type = 1;
					else if(t_char ==1) current_id->type =4;
					else if(t_float==1) current_id->type =3;

				}
				current_tmp=current_id;
			;
    break;}
case 50:
#line 207 "parser.y"
{	
				
				if(current_id->type == 0)
				{
					if(t_int ==1 ) current_id->type = 6;
					else if(t_void == 1) current_id->type = 5;
					else if(t_char ==1) current_id->type =8;
					else if(t_float==1) current_id->type =7;
				}
				current_tmp=current_id;
			;
    break;}
case 51:
#line 219 "parser.y"
{	
				
				yyerrok;
				printError2(NOBRACKET);
			;
    break;}
case 65:
#line 249 "parser.y"
{	

				yyerrok;
				printError2(NOSEMI);
			;
    break;}
case 80:
#line 282 "parser.y"
{
				yyerrok; 
				printError2(INVALIDASSIGN);
			;
    break;}
case 81:
#line 287 "parser.y"
{
				yyerrok; 
				printError2(INVALIDASSIGN);
			;
    break;}
case 82:
#line 292 "parser.y"
{
				yyerrok; 
				printError2(INVALIDASSIGN);
			;
    break;}
case 83:
#line 297 "parser.y"
{
				yyerrok; 
				printError2(INVALIDASSIGN);
			;
    break;}
case 84:
#line 302 "parser.y"
{
				yyerrok; 
				printError2(INVALIDASSIGN);
			;
    break;}
case 85:
#line 307 "parser.y"
{
				yyerrok; 
				printError2(INVALIDASSIGN);
			;
    break;}
case 121:
#line 367 "parser.y"
{		
				yyerrok;
				printError2(NOBRACKET);
			;
    break;}
case 127:
#line 386 "parser.y"
{	
				if(current_id->type == 0)
				{
					current_id->type=13;
				}
			;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 400 "parser.y"


void printLine(int num){
	printf("\t%d\t", num);
}


