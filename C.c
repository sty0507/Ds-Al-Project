#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Person{
   char name[10];
   char li[2];
   char f[5];
};
//���� �ֹ��� �ϸ� �׾Ƴ���
//�� ���� �ֹ� �Ұ�(4ĭ) 
//���� �������� �޴� �߰�(���� �ֹ� ����� �ణ ����->1. n���ڸ����� --�� �ֹ��߽��ϴ�. 2. n+m���ڸ����� --�� �ֹ��߽��ϴ�. ���) 
//���� ������ ���� 
//�������� �޴��� ���� �Ѿ�� ���� ù��° ����� ������ �ƴϸ� ����. 
 
char a[10];
int k = 0; 

void Register(struct Person r[]);
void Show(struct Person r[]);
void Out(struct Person r[]);
void Reset(struct Person r[]);
void Food_list(struct Person r[]);
void Food(struct Person r[]);

int main(){
      int n;
   Reset1(a);
   Reset2(a);
   Reset3(a);
   printf("PC�� ���α׷�(made by ���¿�, ���¹�)\n");
   printf("\n");
      while(1){
         printf("1.��� 2.�ڸ����� 3. �ڸ����� 4.�����ֹ� 5.���� �ֹ� ��� 6.���α׷� ����\n");
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
                  printf("����˴ϴ�");
                  return 0;
      }
   }
}


void Register(struct Person r[]){
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

void Reset1(struct Person r[]){
   int i;
   for(i=0; i<10; i++){
      strcpy(r[i].li, "0");
   }
   return;
}
void Reset2(struct Person r[]){
   int i;
   for(i=0; i<10; i++){
      strcpy(r[i].name, " ");
   }
   return;
}
void Reset3(struct Person r[]){
   int i;
   for(i=0; i<10; i++){
      strcpy(r[i].f, "0");
   }
   return;
}
void Show(struct Person r[]){
      int j;
   for(j=0; j<10; j++){
      printf("%02d�� �ڸ� : %s\n", j+1, r[j].name);
   }
}

void Out(struct Person r[]){
      int s;
      printf("�ڸ��� �Է����ּ���.\n");
      scanf("%d", &s);
     strcpy(r[s-1].name, " ");
   strcpy(r[s-1].li, "0");
   printf("���������� ������ �Ǿ����ϴ�.\n");
   return;
      
   
}

int Search(int d, struct Person r[]){
      if(r[d-1].li=="1")
         return 1;
      else return -1;
}


void Food(struct Person r[]){
   do{
      int food=0, s=0;
      printf("�ڸ� ��ȣ�� �Է��ϼ���.\n");
      scanf("%d", &s);
      printf("1.��� 2.���� 3.����\n");
      scanf("%d", &food);
      switch(food){
         case 1:
            strcpy(r[s-1].f, "1");
            printf("��� �ֹ��� ���������� �Ǿ����ϴ�.%d\n",*(r[s-1].f));
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
void Food_list(struct Person r[]){
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
