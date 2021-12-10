#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Person{
   char name[10];
   char li[2];
   char f[5];
};
//음식 주문을 하면 쌓아놓기
//다 차면 주문 불가(4칸) 
//음식 가져가기 메뉴 추가(음식 주문 기록을 약간 변형->1. n번자리에서 --을 주문했습니다. 2. n+m번자리에서 --을 주문했습니다. 등등) 
//음식 나가는 순서 
//가져가기 메뉴를 통해 넘어가서 제일 첫번째 사람의 음식이 아니면 안줌. 
 
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
   printf("PC방 프로그램(made by 서태영, 정승민)\n");
   printf("\n");
      while(1){
         printf("1.등록 2.자리보기 3. 자리해제 4.음식주문 5.음식 주문 기록 6.프로그램 종료\n");
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
                  printf("종료됩니다");
                  return 0;
      }
   }
}


void Register(struct Person r[]){
      int i, desk=0;
      char name[20];
      printf("자리를 입력하세요(숫자만)\n");
      scanf("%d", &desk);
      printf("이름을 입력하세요(띄어쓰기 금지, 글자만)\n");
      scanf("%s", &name);
      
      
      //에러 확인 코드 
      if(desk==0  || desk >10){
         printf("Error\n");
         return;
      }
   
      //기존에 자리에 사람이 있는지 비교
      int result = Search(desk, r); 
      if(result==1){
         printf("이미 %02d번자리에는 사람이 있습니다.\n", desk);
         return; 
      }
      else{
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
      printf("%02d번 자리 : %s\n", j+1, r[j].name);
   }
}

void Out(struct Person r[]){
      int s;
      printf("자리를 입력해주세요.\n");
      scanf("%d", &s);
     strcpy(r[s-1].name, " ");
   strcpy(r[s-1].li, "0");
   printf("성공적으로 해제가 되었습니다.\n");
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
      printf("자리 번호를 입력하세요.\n");
      scanf("%d", &s);
      printf("1.라면 2.음료 3.과자\n");
      scanf("%d", &food);
      switch(food){
         case 1:
            strcpy(r[s-1].f, "1");
            printf("라면 주문이 정상적으로 되었습니다.%d\n",*(r[s-1].f));
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
void Food_list(struct Person r[]){
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
