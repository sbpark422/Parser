/*
glob.h - global variable for the project
Programmer : (3��) 1615011 ������, 1615017 �ڻ��, 1615019 �ڼ���
Program : ����3 Parser
Date : 2019/06/03
*/

#pragma once
#ifndef __GLOB_H
#define __GLOB_H


#define STsize 1000 //size of string table
#define HTsize 100 //size of hash table

//HTentry����ü�� ����Ű�� ������ HTpointer
typedef struct HTentry *HTpointer;

typedef struct HTentry {
	int index;		//index of identifier in ST
	HTpointer next; //pointer to next identifier
	int type;		//identifier�� Ÿ��
	int line;		//�ٹ�ȣ
} HTentry;

HTpointer HT[HTsize];	//hashtable
char ST[STsize];		//stringtable

int hashcode;    //����� hashcode
int nextid;      //���� identifier
int nextfree;    //available�� StringTable index
int found;       //HashTable���� �������� identifier�� �̹� �����ϴ��� Ȯ���ϴ� ����
int first_idx;   //identifier�� ù��° index

int line_num;			//���� ��ȣ ī��Ʈ
int cErrors;			//���� ī��Ʈ
char * ident;			// identifier�� ������ ����
HTpointer current_id;   //���� ident�� type �ʵ带 ����Ű�� ������
HTpointer current_tmp;  //���� �߻��� type ������ ���� ������

enum errortypes {WRONGST, WRONGFUNC, WRONGDEC, NOFUNCNAME, NOCOMMA, NOSEMI, NOBRACE, NOBRACKET,INVALIDASSIGN}; //���� ���� Ÿ�Ե�
typedef enum errortypes ERR;
ERR error;

#endif// !__GLOB_H