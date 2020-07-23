/*
symtable.c - identifier���� symboltable ����
Programmer : (3��) 1615011 ������, 1615017 �ڻ��, 1615019 �ڼ���
Program : ����3 Parser
Date : 2019/06/03
*/

#pragma warning (disable : 4996)

#include "tn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"

extern void printError(enum tokentypes tn);  

//�о�� identifier�� stringtable�� �Է�
void ReadID() {
   int i = 0;

   nextid = nextfree;
   while (ident[i] != '\0') {
      if (nextfree == STsize) {   //STsize �Ѿ�� overflow ����
         cErrors++;
         printError(TOVERST);
      }
      ST[nextfree] = ident[i];      //�ν��� identifier ��ū�� �� ���ھ� ST�� ����
      nextfree++;
      i++;
   }
}

//�ؽ��ڵ� ���
void ComputeHS(int next_id, int next_free) {
   int sum = 0;
   int st, i;
   for (i = next_id; i < next_free - 1; i++) {
      st = ST[i];
      sum += st;
   }
   hashcode = sum % HTsize;
}

//����� hashcode�� hashtable�� identifier�� �̹� ����ִ��� Ȯ��.
void LookupHS(int next_id, int hash_code) {
   int i, j,k;
   int ht = 0, st = 0;
   HTpointer current;      //���� hashtable ��ġ�� ����Ű�� ������
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
               found = 0;      //�̹� ����ִ� identifier�� �ٸ� identifier�� ���
            else {
               i++;
               j++;
            }
         }	 
      }
   }
}

//���ο� identifier�� hashtable�� ��忡 �߰�
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

//�ν��� identifier ��ū ó��
int SymbolTable() {
   ReadID();
   ST[nextfree] = '\0';
   nextfree++;
   ComputeHS(nextid, nextfree);   //hashcode ���
   LookupHS(nextid, hashcode);      //hashtable Ž��

   if (!found) {
      ADDHT(hashcode);      //hashtable�� ���� �߰�
      return nextid;
   }
   else {
      nextfree = nextid;
      return first_idx;
   }
}

// hashtable�� ����ϰ�, stringtable�� �ִ� character���� ������ ���
void PrintHStable() {
	int i = 0, j;
	HTpointer current;
	printf("\n\n\n [[ HASH TABLE ]] \n");
	while (i<HTsize) {
		if (HT[i] != NULL) {
			  //hashcode ���
			for (current = HT[i]; current != NULL; current = current->next) {
				printf("\n Hash Code %3d : (", i);    

				j = current->index;
				while (ST[j] != '\0' && j < STsize) {
					printf("%c", ST[j]);
					j++;
				}
				printf(" : ");
				// type���� ��� 
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


