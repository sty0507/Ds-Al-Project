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
   	printf("PC방 프로그램(made by 서태영, 정승민)\n");
   	printf("\n");
      	while(1){
        	 printf("1. 등록 2. 자리보기 3. 자리해제 4. 예약현황 5. 규칙 정하기 6. 규칙 보기 7.프로그램 종료\n");
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
                  	printf("종료됩니다");
                  	return 0;
                default:
                   	printf("잘못된 입력입니다.\n");
                   	break;
      }
   }
}
void printAll( Q *q ){
   	int i, j = 1;
   	if((q->front) == (q -> rear)){
   			printf("예약자가 없습니다.\n");
   			return;
	   }
	printf("현재 예약자는 %d명 있습니다.\n", q->rear+1);
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
      printf("예약이 가득 찼습니다.\n");
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
         printf("모든 자리에 사람이 있습니다. 예약하시겠습니까? 1 = Yes / 2 = No ");
         scanf("%d", &yn);
       if(yn == 1){
          	printf("이름을 입력하세요(띄어쓰기 금지, 글자만)\n");
           	scanf("%s", &name);
            x = enQueue(q,name);
            if(x == 1){
            	printf("%s님이 예약이 되었습니다.\n", name);
			}
            return;   
       }
       else if(yn == 2){
            printf("안녕히가십시오..\n");
            return;
       }
       else{
            printf("잘못된 입력입니다.\n");
            return;
       }
     }
      printf("자리를 입력하세요(숫자만)\n");
      scanf("%d", &desk);
      int result = Search(desk, r); 
      if(result==1){
         printf("이미 %02d번자리에는 사람이 있습니다.\n", desk);
         return; 
      }
      printf("이름을 입력하세요(띄어쓰기 금지, 글자만)\n");
      scanf("%s", &name);
      
      
      //에러 확인 코드 
      if(desk==0  || desk >10){
         printf("잘못된 입력입니다.\n");
         return;
      }
   
      //기존에 자리에 사람이 있는지 비교
      
      if(result!=1){
         for(i=0; i<10; i++){
            if((desk-1)==i){
               strcpy(r[i].name, name);
               strcpy(r[i].li, "1");
            printf("성공적으로 등록이 되었습니다.\n");
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
      printf("%02d번 자리 : %s\n", j+1, r[j].name);
   }
}

void Out(P r[]){
   	int s, result = 0;
  	printf("자리를 입력해주세요.\n");
   	scanf("%d", &s);
    result = Search(s, r);
    if(result == 1){
       strcpy(r[s-1].name, " ");
         strcpy(r[s-1].li, "0");
         printf("성공적으로 해제가 되었습니다.\n");
         return;
   }
   else{
      printf("비어있는 자리입니다.\n");
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
   printf("규칙을 입력하십시오.\n");
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
   printf("가 입력되었습니다.\n");
    fclose(fp);
}
void RuleShow(){
   FILE *fp;
   char* pChar;
   int i;
   printf("규칙:\n\n");
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
