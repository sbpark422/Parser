/*
symtable.c - identifier관련 symboltable 관리
Programmer : (3조) 1615011 김지민, 1615017 박상아, 1615019 박수빈
Program : 과제3 Parser
Date : 2019/06/03
*/

#pragma warning (disable : 4996)

#include "tn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"

extern void printError(enum tokentypes tn);  

//읽어온 identifier를 stringtable에 입력
void ReadID() {
   int i = 0;

   nextid = nextfree;
   while (ident[i] != '\0') {
      if (nextfree == STsize) {   //STsize 넘어가면 overflow 에러
         cErrors++;
         printError(TOVERST);
      }
      ST[nextfree] = ident[i];      //인식한 identifier 토큰을 한 문자씩 ST에 넣음
      nextfree++;
      i++;
   }
}

//해시코드 계산
void ComputeHS(int next_id, int next_free) {
   int sum = 0;
   int st, i;
   for (i = next_id; i < next_free - 1; i++) {
      st = ST[i];
      sum += st;
   }
   hashcode = sum % HTsize;
}

//계산한 hashcode로 hashtable에 identifier가 이미 들어있는지 확인.
void LookupHS(int next_id, int hash_code) {
   int i, j,k;
   int ht = 0, st = 0;
   HTpointer current;      //현재 hashtable 위치를 가리키는 포인터
   found = 0;

   if (HT[hash_code] != NULL) {
      for (current = HT[hash_code]; found == 0 && current != NULL; current = current->next) {
         found = 1;
         i = current->index;
         first_idx = i;
         j = next_id;

		 for (k = i;ST[k] != '\0';k++)
			 ht++;
		 for (k = j;ST[k] != '\0';k++)
			 st++;
		 if (ht != st)
			 found = 0;

         while (found == 1 && ST[i] != '\0' && ST[j] != '\0') {
            if (ST[i] != ST[j])
               found = 0;      //이미 들어있던 identifier와 다른 identifier인 경우
            else {
               i++;
               j++;
            }
         }	 
      }
   }
}

//새로운 identifier를 hashtable의 헤드에 추가
void ADDHT(int hash_code) {
	HTpointer p;

   if (HT[hash_code] == NULL) {
	   p = (HTpointer)malloc(sizeof(HTentry));
	   p->type = 0;
	   p->next = NULL;
	   HT[hash_code] = p;
	   p->index = nextid;
	   p->line = line_num;
   }
   else{
	   p = (HTpointer)malloc(sizeof(HTentry));
	   p->type = 0;
	   p->index = nextid;
	   p->next = HT[hash_code];
	   HT[hash_code] = p;
	   p->line = line_num;

   }
   current_id = p;
}

//인식한 identifier 토큰 처리
int SymbolTable() {
   ReadID();
   ST[nextfree] = '\0';
   nextfree++;
   ComputeHS(nextid, nextfree);   //hashcode 계산
   LookupHS(nextid, hashcode);      //hashtable 탐색

   if (!found) {
      ADDHT(hashcode);      //hashtable에 새로 추가
      return nextid;
   }
   else {
      nextfree = nextid;
      return first_idx;
   }
}

// hashtable을 출력하고, stringtable에 있는 character들의 개수를 출력
void PrintHStable() {
	int i = 0, j;
	HTpointer current;
	printf("\n\n\n [[ HASH TABLE ]] \n");
	while (i<HTsize) {
		if (HT[i] != NULL) {
			  //hashcode 출력
			for (current = HT[i]; current != NULL; current = current->next) {
				printf("\n Hash Code %3d : (", i);    

				j = current->index;
				while (ST[j] != '\0' && j < STsize) {
					printf("%c", ST[j]);
					j++;
				}
				printf(" : ");
				// type별로 출력 
				switch (current->type) {
				case 1:
					printf("void scalar variable, line%d)\n", current->line); break;
				case 2:
					printf("integer scalar variable, line%d)\n", current->line); break;
				case 3:
					printf("float scalar variable, line%d)\n", current->line); break;
				case 4:
					printf("character scalar variable, line%d)\n", current->line); break;
				case 5:
					printf("void array variable, line%d)\n", current->line); break;
				case 6:
					printf("integer array variable, line%d)\n", current->line); break;
				case 7:
					printf("float array variable, line%d)\n", current->line); break;
				case 8:
					printf("character array variable, line%d)\n", current->line); break;
				case 9:
					printf("function name, return type = void, line%d)\n", current->line); break;
				case 10:
					printf("function name, return type = integer, line%d)\n", current->line); break;
				case 11:
					printf("function name, return type = float, line%d)\n", current->line); break;
				case 12:
					printf("function name, return type = character, line%d)\n", current->line); break;
				case 13:
					printf("not defined identifier/function, line%d)\n", current->line); break;
				default:
					printf("identifier about parse error, line%d)\n", current->line); break;
				}
			}
		}
		i++;
	}
	printf("\n\n\n < %d characters are used in the string table >\n", nextfree);
}


