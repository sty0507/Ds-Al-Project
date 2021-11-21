#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//문제점 1) show 함수가 그냥 바로 나옴 
// 2) name이 제대로 안들어감-전부 NULL로 취급. 
  
char a[10]={0,0,0,0,0,0,0,0,0,0};
void Register(char a[]);
void Show(char a[]);
void Out();
int main(){
	int i, j;
   int n;
   printf("1.등록 2.자리보기 3. 자리해제 4.프로그램 종료\n");
   scanf("%d", &n);
  	for(i=0; ;i++){
  		switch(n){
      		case 1:
         		Register(a);
      		case 2:
         		Show(a);
      		case 3:
     	    	Out();
      		case 4:
         		return 0;
   }
	  } 
   
}
void Register(char r[]){
   	int desk=0, i, j;
   	char name[20];
   	printf("자리와 이름을 입력하세요\n");
   	scanf("%d %s", &desk, &name);
   	
   	if(desk==0 || desk >10){
   		printf("Error\n");
   		return;
   }
   
   	if(isdigit(name)!=0){
   		printf("숫자를 입력하셨습니다.\n");
   		return;
	   }
	   
   	int result = Search(desk);
   	
   	if(result){
   		return;
   }
	a[(desk-1)] = name;
	printf("성공적으로 등록이 되었습니다.\n");
	return;
}

void Show(char r[]){
   int i;
   	printf("===========================================================================\n");
	printf("    1      2      3      4      5      6      7      8      9      10\n");
	   printf("---------------------------------------------------------------------------\n");
   	for(i=0; i<10;i++){
   		if(r[i]==0)
   			printf("   NULL");
   		else
   			printf("%5s", r[i]);
   }
   printf("\n===========================================================================\n");
}

void Out(){
   
}

int Search(int desk){
   if(a[(desk-1)==0])
   	return 1;
   	else return -1;
}
