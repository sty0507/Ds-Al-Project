#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Person{
   char name[10];
   char li[2];
   char f[5];
}P;
//���� �ֹ��� �ϸ� �׾Ƴ���
//�� ���� �ֹ� �Ұ�(4ĭ) 
//���� �������� �޴� �߰�(���� �ֹ� ����� �ణ ����->1. n���ڸ����� --�� �ֹ��߽��ϴ�. 2. n+m���ڸ����� --�� �ֹ��߽��ϴ�. ���) 
//���� ������ ���� 
//�������� �޴��� ���� �Ѿ�� ���� ù��° ����� ������ �ƴϸ� ����. 
 
char a[10];
int k = 0; 

void Register(P r[]);
void Show(P r[]);
void Out(P r[]);
void Reset(P r[]);
void Food_list(P r[]);
void Food(P r[]);

int main(){
      int n;
   Reset1(a);
   Reset2(a);
   Reset3(a);
   printf("PC�� ���α׷�(made by ���¿�, ���¹�)\n");
   printf("\n");
      while(1){
         printf("1.��� 2.�ڸ����� 3. �ڸ����� 4.�����ֹ� 5.���� �ֹ� ��� 6. ��Ģ ���ϱ� 7. ��Ģ ���� 8.���α׷� ����\n");
         n = 0;
         scanf("%d", &n);
           switch(n){
               case 1:
                  Register(a);
                  break;
               case 2:
                  Show(a);
                  break;
               case 3:
                  Out(a);
                  break;
               case 4:
                  Food(a);
                  break;
               case 5:
                  Food_list(a);
                  break;
               case 6:
                  Rule();
                  break;
               case 7:
                  RuleShow();
                  break;
               case 8:
                  printf("����˴ϴ�");
                  return 0;
                default:
                   printf("�߸��� �Է��Դϴ�.\n");
                   break;
      }
   }
}

void Rule(){
   FILE* fp;
    char rule[1000], enter;
   printf("��Ģ�� �Է��Ͻʽÿ�.\n");
   scanf("%c",&enter);
   scanf("%[^\n]s",rule);
    
    fp = fopen("Rule.txt","at");
    if(fp==NULL){
       printf("Error");
       return;
   }
    fputs(rule,fp);
    fputs("\n\n",fp);
   printf("\"%s\"",rule);
   printf("�� �ԷµǾ����ϴ�.\n");
    fclose(fp);
}
void RuleShow(){
   FILE *fp;
   char* pChar;
   int i;
   printf("��Ģ:\n\n");
   fp = fopen("Rule.txt","rt");
   char rule[1000];
   for(i=0; i<sizeof(rule); i++){
      if(fgets(rule, sizeof(rule), fp)==NULL) break;
      printf("%s",rule);
   }
   printf("\n");
   fclose(fp);
   return;
}
void Register(P r[]){
      int i, desk=0;
      char name[20];
      printf("�ڸ��� �Է��ϼ���(���ڸ�)\n");
      scanf("%d", &desk);
      printf("�̸��� �Է��ϼ���(���� ����, ���ڸ�)\n");
      scanf("%s", &name);
      
      
      //���� Ȯ�� �ڵ� 
      if(desk==0  || desk >10){
         printf("Error\n");
         return;
      }
   
      //������ �ڸ��� ����� �ִ��� ��
      int result = Search(desk, r); 
      if(result==1){
         printf("�̹� %02d���ڸ����� ����� �ֽ��ϴ�.\n", desk);
         return; 
      }
      else{
         for(i=0; i<10; i++){
            if((desk-1)==i){
               strcpy(r[i].name, name);
               strcpy(r[i].li, "1");
            printf("���������� ����� �Ǿ����ϴ�.\n");
            return;
         }
         else continue;
      }
      return;
    }
}

void Reset1(P r[]){
   int i;
   for(i=0; i<10; i++){
      strcpy(r[i].li, "0");
   }
   return;
}
void Reset2(P r[]){
   int i;
   for(i=0; i<10; i++){
      strcpy(r[i].name, " ");
   }
   return;
}
void Reset3(P r[]){
   int i;
   for(i=0; i<10; i++){
      strcpy(r[i].f, "0");
   }
   return;
}
void Show(P r[]){
      int j;
   for(j=0; j<10; j++){
      printf("%02d�� �ڸ� : %s\n", j+1, r[j].name);
   }
}

void Out(P r[]){
   int s, result = 0;
   printf("�ڸ��� �Է����ּ���.\n");
   scanf("%d", &s);
    result = Search(s, r);
    if(result == 1){
       strcpy(r[s-1].name, " ");
         strcpy(r[s-1].li, "0");
         printf("���������� ������ �Ǿ����ϴ�.\n");
         return;
   }
   else{
      printf("����ִ� �ڸ��Դϴ�.\n");
      return;
   }
    
}

int Search(int d, P r[]){
      if(*(r[d-1].li)=='1')
         return 1;
      else return -1;
}


void Food(P r[]){
   do{
      int food=0, s=0;
      printf("�ڸ� ��ȣ�� �Է��ϼ���. �ֹ��� �� �ڸ��� �� ���� �����մϴ�.\n");
      scanf("%d", &s);
      if(Search(s,r)) 
     {
          printf("%02d�� �ڸ����� ����� �����ϴ�.\n",s);
         break;   
     }
      printf("1.��� 2.���� 3.����\n");
      scanf("%d", &food);
      switch(food){
         case 1:
            strcpy(r[s-1].f, "1");
            printf("��� �ֹ��� ���������� �Ǿ����ϴ�.\n");
            return;
         case 2:
            strcpy(r[s-1].f, "2");
            printf("���� �ֹ��� ���������� �Ǿ����ϴ�.\n");
            return;
         case 3:
            strcpy(r[s-1].f, "3");
            printf("���� �ֹ��� ���������� �Ǿ����ϴ�.\n");
            return;
      }
   }while(1);
   
}
void Food_list(P r[]){
   int n, s, i;
   printf("1.��ü  OR 2.Ư���ڸ�\n");
   scanf("%d", &n);
   do{
      switch(n){
      case 1:
         for(i=0; i<10; i++){
            Food_print(r, i);
         }
         return;
      case 2:
         printf("�ڸ��� �Է��ϼ���\n");
         scanf("%d", &s);
         Food_print(r,s-1); 
         return;
      }
   }while(1);
}
void Food_print(struct Person r[], int i){
   if(*(r[i].f)=='1'){
      printf("%02d�� �ڸ������� ����� �ֹ��߽��ϴ�.\n", i+1);
      return;
   }
   else if(*(r[i].f)=='2'){
      printf("%02d�� �ڸ������� ���Ḧ �ֹ��߽��ϴ�.\n", i+1);
      return;
   }
   else if(*(r[i].f)=='3'){
      printf("%02d�� �ڸ������� ���ڸ� �ֹ��߽��ϴ�.\n", i+1);
      return;
   }
   else{
      printf("%02d�� �ڸ��� ������ �ֹ����� �ʾҽ��ϴ�.\n", i+1);
      return;
   }
}
