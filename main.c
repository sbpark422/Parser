/*
main.c - �� token�� ���� ��� 
Programmer : (3��) 1615011 ������, 1615017 �ڻ��, 1615019 �ڼ���
Program : ����3 Parser
Date : 2019/06/03

- endif������� ����
- ���� ������ ���� -
WRONGST : �߸��� statement ���� 
WRONGFUNC : �߸��� �Լ��� ���� �� ���� 
WRONGDEC : �߸��� ������ �� ���� ( (��) int ;  )
NOFUNCNAME :  �Լ����� ���� ���� (  (��) int (int a, int b)  )
NOCOMMA : �Ķ���� ����Ʈ �ȿ� �޸�(,)�� ���� ���� ( (��)  int func(int a int b) )
NOSEMI: �����ݷ��� ���� ����
NOBRACE : �߰�ȣ�� ���� ����
NOBRACKET : ���ȣ�� ���� ���� 
INVALIDASSIGN : �߸��� assignment ���� 

*/

#pragma warning (disable:4996)

#include "tn.h"
#include "glob.h"
#include <stdio.h>
#include <stdlib.h>

extern int SymbolTable();						//����1�� identifier�� symboltable�� �ִ� �Լ�
extern void printError(enum tokentypes tn);		//���� �޼��� ��� �Լ�
extern void PrintHStable();						// �ؽ����̺� ��� �Լ�
extern void printError2(ERR e);					//���� ��� �Լ�

extern yylex();				// scanner
extern char * yytext;		//���� �ν��� ����(��)�� ��� �ִ� ������
extern int yyleng;			//���� �ν��� ����(��)�� ����
extern int yyparse();		// parser



//���� �ν��� token type���� ó���ϴ� �Լ�
void printtoken(enum tokentypese tn) {
	switch (tn) {
	case TIDENT:			//���� identifier�ΰ�� Symbol Table ����
		ident = yytext;
		SymbolTable();
		break;
	case TILLIDENT1:		//digit���� identifier ���� ó��
		cErrors++;
		printError(tn);
		break;
	case TILLIDENT2:		//too long identifier ���� ó��
		cErrors++;
		printError(tn);
		break;
	case TERROR:			// illegal character ���� ó��
		cErrors++;
		printError(tn);
		break;
	}
}

//���� �Լ�
int main()
{

	printf("\n*** MiniC parsing begins\n\n");
	current_id = (HTpointer)malloc(sizeof(HTentry));
	current_tmp = (HTpointer)malloc(sizeof(HTentry));

	//�ʱⰪ ����
	current_id->type = 0;
	current_id->next = NULL;
	current_tmp=current_id;

	cErrors=0;				//���� ���� ī��Ʈ ����
	line_num=1;				//�Է� ���� �� ��ȣ
	nextid = 0;				//���� identifier
	nextfree = 0;			//available�� StringTable index

	yyparse();				// �Ľ� ����

	printf("\nParsing ends. ***\n");
	printf("\n\n%d error(s) detected\n", cErrors);

	PrintHStable();			//�ؽ����̺� ���
	return 0;
}
