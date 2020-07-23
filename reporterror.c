/*
reporterror.c - 에러별로 출력
Programmer : (3조) 1615011 김지민, 1615017 박상아, 1615019 박수빈
Program : 과제3 Parser
Date : 2019/06/03
*/

#pragma warning(disable:4996)

#include"tn.h"
#include<stdio.h>
#include<stdlib.h>
#include "glob.h"

extern char * yytext;
extern printLine(int line_num);
extern yylex();

yyerror(s)
char *s;
{

}

//현재 인식한 토큰에 대한 에러메세지를 출력하는 함수
void printError(enum tokentypes tn) {
	switch (tn) {
	case TILLIDENT1:			//잘못된 identifier의 경우(digit으로 시작하는 경우...)
		printf("**TERROR**\t\t%s illegal IDENT (start with digit)\n", yytext);
		break;

	case TILLIDENT2:			//잘못된 identifier의 경우(10자가 넘는 경우...)
		printf("**TERROR**\t\t%s illegal IDENT (too long)\n", yytext);
		break;

	case TOVERST:				// overflow
		printf("**TERROR**\t\t**OVERFLOW**\n");
		printf("\n***** %d errors detected\n", cErrors);  //에러개수 출력 후 
		exit(0);     // 프로그램 종료
		break;

	case TERROR:				//잘못된 문자 에러 처리
		printf("**TERROR**\t\t%s illegal Character\n", yytext);
		break;
	}
}

void printError2(ERR e) {
	switch (e) {
	case WRONGST :		// statement 에러
		printLine(line_num);
		printf("\t 잘못된 statement 입니다.\n");
		cErrors++;
		break;
	case WRONGFUNC :   // function 에러
		printLine(line_num);
		printf("\t 잘못된 함수의 정의입니다.\n");
		cErrors++;
		break;
	case WRONGDEC :		// 선언 에러
		printLine(line_num);
		printf("\t 잘못된 선언입니다.\n");
		cErrors++;
		break;
	case NOFUNCNAME :	// 함수명 에러
		printLine(line_num);
		printf("\t 함수명이 잘못되었습니다.\n");
		cErrors++;
		break;
	case NOCOMMA :		// 콤마관련 에러
		printLine(line_num);
		printf("\t 콤마(,)가 없습니다.\n");
		cErrors++;
		break;
	case NOSEMI :		// 세미콜론이 없는 경우
		printLine(line_num);
		printf("\t 세미콜론(;)이 없습니다.\n");
		cErrors++;
		break;
	case NOBRACE :		// 중괄호 에러
		printLine(line_num);
		printf("\t brace({,})가 없습니다.\n");
		cErrors++;
		break;
	case NOBRACKET:		// 대괄호 에러
		printLine(line_num);
		printf("\t bracket([,])가 없습니다.\n");
		cErrors++;
		break;
	case INVALIDASSIGN:		// assignment 에러
		printLine(line_num);
		printf("\t 잘못된 assignment입니다.\n");
		cErrors++;
		break;

	}
}