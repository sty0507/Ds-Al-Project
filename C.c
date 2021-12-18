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
//음식 주문을 하면 쌓아놓기
//다 차면 주문 불가(4칸) 
//음식 가져가기 메뉴 추가(음식 주문 기록을 약간 변형->1. n번자리에서 --을 주문했습니다. 2. n+m번자리에서 --을 주문했습니다. 등등) 
//음식 나가는 순서 
//가져가기 메뉴를 통해 넘어가서 제일 첫번째 사람의 음식이 아니면 안줌. 
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
void Out(P r[]);
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
   	printf("PC방 프로그램(made by 서태영, 정승민)\n");
   	printf("\n");
      	while(1){
        	 printf("1. 등록 2. 자리보기 3. 자리해제 4. 예약현황 5. 음식주문 6. 음식 주문 기록 7. 규칙 정하기 8. 규칙 보기 9.프로그램 종료\n");
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
               case 9:
                  printf("종료됩니다");
                  return 0;
                default:
                   printf("잘못된 입력입니다.\n");
                   break;
      }
   }
}
void printAll( Q *q ){
   int i;
   for(i = q -> front+1; i <= q -> rear; i++)
      printf("%d ", q -> buf[i]);
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
	int f = 0;
	f = QueueisFull(q);
	printf("%d", f);
   	if(f == 1){
   	  (q -> rear)++;
	  q -> buf[(q -> rear)] = data;
      printf("%s님이 예약되었습니다.\n",data);
      return;
      
   	}
   	else
   	{	
      printf("예약이 가득 찼습니다.\n");
      return;
   	}
}

int QueueisFull( Q *q ){
   	if((q -> rear) == (q -> size)-1)
      	return -1;
   	else
      	return 1;
}

void Register(P r[], Q q[]){
      int i, desk=0,yn;
      char name[20];
     if(isfull(r)){
         printf("모든 자리에 사람이 있습니다. 예약하시겠습니까? 1 = Yes / 2 = No ");
         scanf("%d", &yn);
       if(yn == 1){
          	printf("이름을 입력하세요(띄어쓰기 금지, 글자만)\n");
           	scanf("%s", &name);
            enQueue(q,name);
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


void Food(P r[]){
   do{
      int food=0, s=0;
      printf("자리 번호를 입력하세요. 주문은 한 자리당 한 번만 가능합니다.\n");
      scanf("%d", &s);
      if(Search(s,r)) 
     {
          printf("%02d번 자리에는 사람이 없습니다.\n",s);
         break;   
     }
      printf("1.라면 2.음료 3.과자\n");
      scanf("%d", &food);
      switch(food){
         case 1:
            strcpy(r[s-1].f, "1");
            printf("라면 주문이 정상적으로 되었습니다.\n");
            return;
         case 2:
            strcpy(r[s-1].f, "2");
            printf("음료 주문이 정상적으로 되었습니다.\n");
            return;
         case 3:
            strcpy(r[s-1].f, "3");
            printf("과자 주문이 정상적으로 되었습니다.\n");
            return;
      }
   }while(1);
   
}
void Food_list(P r[]){
   int n, s, i;
   printf("1.전체  OR 2.특정자리\n");
   scanf("%d", &n);
   do{
      switch(n){
      case 1:
         for(i=0; i<10; i++){
            Food_print(r, i);
         }
         return;
      case 2:
         printf("자리를 입력하세요\n");
         scanf("%d", &s);
         Food_print(r,s-1); 
         return;
      }
   }while(1);
}
void Food_print(struct Person r[], int i){
   if(*(r[i].f)=='1'){
      printf("%02d번 자리에서는 라면을 주문했습니다.\n", i+1);
      return;
   }
   else if(*(r[i].f)=='2'){
      printf("%02d번 자리에서는 음료를 주문했습니다.\n", i+1);
      return;
   }
   else if(*(r[i].f)=='3'){
      printf("%02d번 자리에서는 과자를 주문했습니다.\n", i+1);
      return;
   }
   else{
      printf("%02d번 자리는 음식을 주문하지 않았습니다.\n", i+1);
      return;
   }
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
