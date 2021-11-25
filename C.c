#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM 10

//문제점 1) show 함수가 그냥 바로 나옴 
// 2) name이 제대로 안들어감-전부 NULL로 취급. 

struct Person{
	char name[10];
	int li[10];
};
  
char a[10];
int k = 0;
void Register(struct Person r[]);
void Show(struct Person r[]);
void Out(struct Person r[]);
void Food();

int main(){
	int i, j;
   	int n;
   	while(1){
   		printf("1.등록 2.자리보기 3. 자리해제 4.음식주문 5.프로그램 종료\n");
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
	     	    	Food();
	     	    	break;
	      		case 5:
	         		return 0;
	   }
	}
}
void Register(struct Person r[]){
   	int desk=0, i, j;
   	char name[20];
   	printf("자리와 이름을 입력하세요(띄어쓰기 금지)\n");
   	scanf("%d %s", &desk, &name);
   	
   	if(desk==0 || desk >10){
   		printf("Error\n");
   		return;
   	}
   	
   	int result = Search(desk);//기존에 자리에 사람이 있는지 비교 
   	if(result==1){
   		return; 
   	}
   	else{
   		strcpy(r[k].name, name);
   		strcpy(r[k].li, 1);
		printf("성공적으로 등록이 되었습니다.\n");
		k++;
		return;
   }
	
}

void Show(struct Person r[]){
   	int j;
   	printf("===========================================================================\n");
	printf("    1      2      3      4      5      6      7      8      9      10\n");
	printf("---------------------------------------------------------------------------\n");
  	for(j=0; j<10;j++){
   		if(r[j].li == 0)
   			printf("   NULL");
   		else
   			printf("%s", r[j].name);
   }
   printf("\n===========================================================================\n");
}

void Out(struct Person r[]){
   int s;
   printf("자리를 입력해주세요.\n");
   scanf("%d", &s);
   r[s-1].li == 0;
   return;
}

int Search(int desk){
   	if(a[(desk-1)==0])
   		return 1;
   	else return -1;
}
void Food(){
	do{
		int f=0;
		printf("1.라면 2.음료 3.과자");
		scanf("%d", &f);
		switch(f){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}while(1);
	
}
