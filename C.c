#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char ELEMENT;
typedef struct Person{
   char name[10];
   char li[2];
}P;

 
typedef struct reservation{
   ELEMENT * buf;
   int front;
   int rear;
   int size;
}Q;

char a[10];
int k = 0; 

ELEMENT getData(Q *node, int i);
void Register(P r[], Q q[]);
void Show(P r[]);
void Out(P r[]);
void Reset(P r[]);
int isFull( Q *q );
Q * createQueue( int n );
int QueueisFull( Q *q );
int enQueue( Q *q, ELEMENT data );
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
   	printf("PC�� ���α׷�(made by ���¿�, ���¹�)\n");
   	printf("\n");
      	while(1){
        	 printf("1. ��� 2. �ڸ����� 3. �ڸ����� 4. ������Ȳ 5. ��Ģ ���ϱ� 6. ��Ģ ���� 7.���α׷� ����\n");
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
                  Out(a);
                  	break;
               case 4:
                 	printAll(q);
              		break; 
               case 5:
                  	Rule();
                  	break;
               case 6:
                  	RuleShow();
                  	break;
               case 7:
                  	printf("����˴ϴ�");
                  	return 0;
                default:
                   	printf("�߸��� �Է��Դϴ�.\n");
                   	break;
      }
   }
}
void printAll( Q *q ){
   	int i, j = 1;
   	if((q->front) == (q -> rear)){
   			printf("�����ڰ� �����ϴ�.\n");
   			return;
	   }
	printf("���� �����ڴ� %d�� �ֽ��ϴ�.\n", q->rear+1);
    return;
}

Q * createQueue( int n ){
   Q *temp = (Q *) malloc( sizeof(Q) );
   temp -> size = n;
   temp -> rear = -1;
   temp -> front = -1;
   temp -> buf = (ELEMENT *) malloc(sizeof(ELEMENT)*n);
   return temp;
}

int enQueue( Q *q, ELEMENT data ){
	int f = 0;
	f = QueueisFull(q);
	if(f == 1){
		(q -> rear) ++;
		q -> buf[(q->rear)] = data;
		return 1;
	}
   	else
   	{	
      printf("������ ���� á���ϴ�.\n");
      return -1;
   	}
}

int QueueisFull( Q *q ){
   	if((q -> rear) == (q -> size)-1)
      	return -1;
   	else
      	return 1;
}

void Register(P r[], Q q[]){
      int i, desk=0,yn, x = 0;
      char name[20];
     if(isfull(r)){
         printf("��� �ڸ��� ����� �ֽ��ϴ�. �����Ͻðڽ��ϱ�? 1 = Yes / 2 = No ");
         scanf("%d", &yn);
       if(yn == 1){
          	printf("�̸��� �Է��ϼ���(���� ����, ���ڸ�)\n");
           	scanf("%s", &name);
            x = enQueue(q,name);
            if(x == 1){
            	printf("%s���� ������ �Ǿ����ϴ�.\n", name);
			}
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
      int result = Search(desk, r); 
      if(result==1){
         printf("�̹� %02d���ڸ����� ����� �ֽ��ϴ�.\n", desk);
         return; 
      }
      printf("�̸��� �Է��ϼ���(���� ����, ���ڸ�)\n");
      scanf("%s", &name);
      
      
      //���� Ȯ�� �ڵ� 
      if(desk==0  || desk >10){
         printf("�߸��� �Է��Դϴ�.\n");
         return;
      }
   
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

ELEMENT getData(Q *q, int i){
	return (q -> buf[i]);
}
