/*
main.c - 각 token에 대한 출력 
Programmer : (3조) 1615011 김지민, 1615017 박상아, 1615019 박수빈
Program : 과제3 Parser
Date : 2019/06/03

- endif방법으로 구현
- 따로 정의한 에러 -
WRONGST : 잘못된 statement 에러 
WRONGFUNC : 잘못된 함수가 정의 된 에러 
WRONGDEC : 잘못된 선언이 된 에러 ( (예) int ;  )
NOFUNCNAME :  함수명이 없는 에러 (  (예) int (int a, int b)  )
NOCOMMA : 파라미터 리스트 안에 콤마(,)가 없는 에러 ( (예)  int func(int a int b) )
NOSEMI: 세미콜론이 없는 에러
NOBRACE : 중괄호가 없는 에러
NOBRACKET : 대괄호가 없는 에러 
INVALIDASSIGN : 잘못된 assignment 에러 

*/

#pragma warning (disable:4996)

#include "tn.h"
#include "glob.h"
#include <stdio.h>
#include <stdlib.h>

extern int SymbolTable();						//과제1의 identifier를 symboltable에 넣는 함수
extern void printError(enum tokentypes tn);		//에러 메세지 출력 함수
extern void PrintHStable();						// 해쉬테이블 출력 함수
extern void printError2(ERR e);					//에러 출력 함수

extern yylex();				// scanner
extern char * yytext;		//현재 인식한 문자(열)을 담고 있는 포인터
extern int yyleng;			//현재 인식한 문자(열)의 길이
extern int yyparse();		// parser



//현재 인식한 token type별로 처리하는 함수
void printtoken(enum tokentypese tn) {
	switch (tn) {
	case TIDENT:			//정상 identifier인경우 Symbol Table 관리
		ident = yytext;
		SymbolTable();
		break;
	case TILLIDENT1:		//digit시작 identifier 에러 처리
		cErrors++;
		printError(tn);
		break;
	case TILLIDENT2:		//too long identifier 에러 처리
		cErrors++;
		printError(tn);
		break;
	case TERROR:			// illegal character 에러 처리
		cErrors++;
		printError(tn);
		break;
	}
}

//메인 함수
int main()
{

	printf("\n*** MiniC parsing begins\n\n");
	current_id = (HTpointer)malloc(sizeof(HTentry));
	current_tmp = (HTpointer)malloc(sizeof(HTentry));

	//초기값 지정
	current_id->type = 0;
	current_id->next = NULL;
	current_tmp=current_id;

	cErrors=0;				//에러 개수 카운트 변수
	line_num=1;				//입력 파일 줄 번호
	nextid = 0;				//현재 identifier
	nextfree = 0;			//available한 StringTable index

	yyparse();				// 파싱 진행

	printf("\nParsing ends. ***\n");
	printf("\n\n%d error(s) detected\n", cErrors);

	PrintHStable();			//해쉬테이블 출력
	return 0;
}
