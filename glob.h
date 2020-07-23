/*
glob.h - global variable for the project
Programmer : (3조) 1615011 김지민, 1615017 박상아, 1615019 박수빈
Program : 과제3 Parser
Date : 2019/06/03
*/

#pragma once
#ifndef __GLOB_H
#define __GLOB_H


#define STsize 1000 //size of string table
#define HTsize 100 //size of hash table

//HTentry구조체를 가리키는 포인터 HTpointer
typedef struct HTentry *HTpointer;

typedef struct HTentry {
	int index;		//index of identifier in ST
	HTpointer next; //pointer to next identifier
	int type;		//identifier의 타입
	int line;		//줄번호
} HTentry;

HTpointer HT[HTsize];	//hashtable
char ST[STsize];		//stringtable

int hashcode;    //계산할 hashcode
int nextid;      //현재 identifier
int nextfree;    //available한 StringTable index
int found;       //HashTable에서 넣으려는 identifier가 이미 존재하는지 확인하는 변수
int first_idx;   //identifier의 첫번째 index

int line_num;			//라인 번호 카운트
int cErrors;			//에러 카운트
char * ident;			// identifier를 전달할 변수
HTpointer current_id;   //현재 ident의 type 필드를 가리키는 포인터
HTpointer current_tmp;  //에러 발생시 type 수정을 위한 포인터

enum errortypes {WRONGST, WRONGFUNC, WRONGDEC, NOFUNCNAME, NOCOMMA, NOSEMI, NOBRACE, NOBRACKET,INVALIDASSIGN}; //에러 관련 타입들
typedef enum errortypes ERR;
ERR error;

#endif// !__GLOB_H