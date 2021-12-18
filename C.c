#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char ELEMENT;

typedef struct Person{
   char name[10];
   char li[2];
   char f[5];
}P;

typedef struct reservation{
   ELEMENT * buf;
   int front;
   int rear;
   int size;
}Q;

char a[10];
int k = 0; 

void Register(P r[], Q q[]);
void Show(P r[]);
void Out(P r[] ,Q q[]);
void Reset(P r[]);
void Food_list(P r[]);
void Food(P r[]);
int isFull( Q *q );
Q * createQueue( int n );
int QueueisFull( Q *q );
void enQueue( Q *q, ELEMENT data );
int isEmpty( Q *q );
ELEMENT deQueue( Q *q );
void destroyQueue( Q * q );
void printAll( Q *q );

int main(){
     Q *q;
     q = createQueue(10);
      int n;
   Reset1(a);
   Reset2(a);
   Reset3(a);
   printf("PC�� ���α׷�(made by ���¿�, ���¹�)\n");
   printf("\n");
      while(1){
         printf("1. ��� 2. �ڸ����� 3. �ڸ����� 4. ������Ȳ 5. �����ֹ� 6. ���� �ֹ� ��� 7. ��Ģ ���ϱ� 8. ��Ģ ���� 0.���α׷� ����\n");
         n = 0;
         scanf("%d", &n);
           switch(n){
               case 1:
                  Register(a,q);
                  break;
               case 2:
                  Show(a);
                  break;
               case 3:
                  Out(a,q);
                  break;
               case 4:
                 printAll(q);
              break; 
               case 5:
                  Food(a);
                  break;
               case 6:
                  Food_list(a);
                  break;
               case 7:
                  Rule();
                  break;
               case 8:
                  RuleShow();
                  break;
               case 0:
                  printf("���� PC���� �̿��� �ּż� �����մϴ�. �ȳ������ʽÿ�.");
                  return 0;
                default:
                   printf("�߸��� �Է��Դϴ�.\n");
                   break;
      }
   }
}

void printAll( Q *q ){
   int i;
   if(isEmpty(q)){
      printf("����� �մ��� �����ϴ�.");
   }
   else{
      for(i = q -> front+1; i <= q -> rear; i++)
      printf("%d��\n", q -> buf[i]);
   }
}

Q * createQueue( int n ){
   Q *temp = (Q *) malloc( sizeof(Q) );
   temp -> size = n;
   temp -> rear = -1;
   temp -> front = -1;
   temp -> buf = (ELEMENT *) malloc(sizeof(ELEMENT)*n);
   return temp;
}

void enQueue( Q *q, ELEMENT data ){
   if(QueueisFull(q))
   {
      printf("������ ���� á���ϴ�.\n");
      return;
   }
   else
   {
      q -> buf[++q -> rear] = data;
      printf("%s���� ����Ǿ����ϴ�.\n",data);
      return; 
   }
}

int QueueisFull( Q *q ){
   if(q -> rear == q -> size-1){
      return 1;
   }
   else{
      //����� �Ѿ�� �� �ٵ� �� ������ 
      return -1;
   }
}

void Register(P r[], Q q[]){
      int i, desk=0,yn;
      char name[20];
     if(isfull(r)){
         printf("��� �ڸ��� ����� �ֽ��ϴ�. �����Ͻðڽ��ϱ�? 1 = Yes / 2 = No ");
         scanf("%d",&yn);
       if(yn == 1){
          printf("�̸��� �Է��ϼ���(���� ����, ���ڸ�)\n");
           scanf("%s", &name);
            enQueue(q,name);
            return;   
       }
       else if(yn == 2){
            printf("�ȳ������ʽÿ�..\n");
            return;
       }
       else{
            printf("�߸��� �Է��Դϴ�.\n");
            return;
       }
     }
      printf("�ڸ��� �Է��ϼ���(���ڸ�)\n");
      scanf("%d", &desk);
     if(desk==0  || desk >10){
         printf("�߸��� �Է��Դϴ�.\n");
         return;
      }
      int result = Search(desk, r); 
      if(result==1){
         printf("�̹� %02d���ڸ����� ����� �ֽ��ϴ�.\n", desk);
         return; 
      }
      printf("�̸��� �Է��ϼ���(���� ����, ���ڸ�)\n");
      scanf("%s", &name);
   
      //������ �ڸ��� ����� �ִ��� ��
      
      if(result!=1){
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

int isfull(P r[]){
   int i;
   for(i=0; i<10; i++){
      if(*(r[i].li)!='1'){
         return 0;
      }
   }
   return 1;
}


void Show(P r[]){
      int j;
   for(j=0; j<10; j++){
      printf("%02d�� �ڸ� : %s\n", j+1, r[j].name);
   }
}

int isEmpty( Q *q ){
   if(q -> rear == q -> front)
      return 1;
   else
      return 0;
}

ELEMENT deQueue( Q *q ){
   return q -> buf[++q->front]; 
}

void Out(P r[],Q q[]){
   int s, result = 0;
   printf("�ڸ��� �Է����ּ���.\n");
   scanf("%d", &s);
    result = Search(s, r);
    if(result == 1){
       printf("%s�մ�, �ȳ������ʽÿ�.\n",r[s-1].name); 
       strcpy(r[s-1].name, " ");
         strcpy(r[s-1].li, "0");
         if(!(isEmpty(q))){
            printf("���� �մ� %s���� �����̽��ϴ�.\n",deQueue(q));
       }
         return;
   }
   else{
      printf("����ִ� �ڸ��Դϴ�.\n");
      return;
   }
    
}

void destroyQueue( Q * q ){
   free(q -> buf);
   free(q);
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
    fputs("\n",fp);
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
