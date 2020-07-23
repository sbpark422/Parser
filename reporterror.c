/*
reporterror.c - �������� ���
Programmer : (3��) 1615011 ������, 1615017 �ڻ��, 1615019 �ڼ���
Program : ����3 Parser
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

//���� �ν��� ��ū�� ���� �����޼����� ����ϴ� �Լ�
void printError(enum tokentypes tn) {
	switch (tn) {
	case TILLIDENT1:			//�߸��� identifier�� ���(digit���� �����ϴ� ���...)
		printf("**TERROR**\t\t%s illegal IDENT (start with digit)\n", yytext);
		break;

	case TILLIDENT2:			//�߸��� identifier�� ���(10�ڰ� �Ѵ� ���...)
		printf("**TERROR**\t\t%s illegal IDENT (too long)\n", yytext);
		break;

	case TOVERST:				// overflow
		printf("**TERROR**\t\t**OVERFLOW**\n");
		printf("\n***** %d errors detected\n", cErrors);  //�������� ��� �� 
		exit(0);     // ���α׷� ����
		break;

	case TERROR:				//�߸��� ���� ���� ó��
		printf("**TERROR**\t\t%s illegal Character\n", yytext);
		break;
	}
}

void printError2(ERR e) {
	switch (e) {
	case WRONGST :		// statement ����
		printLine(line_num);
		printf("\t �߸��� statement �Դϴ�.\n");
		cErrors++;
		break;
	case WRONGFUNC :   // function ����
		printLine(line_num);
		printf("\t �߸��� �Լ��� �����Դϴ�.\n");
		cErrors++;
		break;
	case WRONGDEC :		// ���� ����
		printLine(line_num);
		printf("\t �߸��� �����Դϴ�.\n");
		cErrors++;
		break;
	case NOFUNCNAME :	// �Լ��� ����
		printLine(line_num);
		printf("\t �Լ����� �߸��Ǿ����ϴ�.\n");
		cErrors++;
		break;
	case NOCOMMA :		// �޸����� ����
		printLine(line_num);
		printf("\t �޸�(,)�� �����ϴ�.\n");
		cErrors++;
		break;
	case NOSEMI :		// �����ݷ��� ���� ���
		printLine(line_num);
		printf("\t �����ݷ�(;)�� �����ϴ�.\n");
		cErrors++;
		break;
	case NOBRACE :		// �߰�ȣ ����
		printLine(line_num);
		printf("\t brace({,})�� �����ϴ�.\n");
		cErrors++;
		break;
	case NOBRACKET:		// ���ȣ ����
		printLine(line_num);
		printf("\t bracket([,])�� �����ϴ�.\n");
		cErrors++;
		break;
	case INVALIDASSIGN:		// assignment ����
		printLine(line_num);
		printf("\t �߸��� assignment�Դϴ�.\n");
		cErrors++;
		break;

	}
}