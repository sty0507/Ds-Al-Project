#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//������ 1) show �Լ��� �׳� �ٷ� ���� 
// 2) name�� ����� �ȵ�-���� NULL�� ���. 
  
char a[10]={0,0,0,0,0,0,0,0,0,0};
void Register(char r[]);
void Show(char r[]);
void Out(char r[]);
void Food();
int main(){
	int i, j;
   int n;
   do{
   		printf("1.��� 2.�ڸ����� 3. �ڸ����� 4.�����ֹ� 5.���α׷� ����\n");
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
	}while(1);
}
void Register(char r[]){
   	int desk=0, i, j;
   	char name[20];
   	printf("�ڸ��� �̸��� �Է��ϼ���(������� ����)\n");
   	scanf("%d %s", &desk, &name);
   	
   	if(desk==0 || desk >10){
   		printf("Error\n");
   		return;
   	}
   	
   	int result = Search(desk);//������ �ڸ��� ����� �ִ��� �� 
   	if(result==1){
   		return; 
   	}
   	else{
   		a[(desk-1)] = name;
		printf("���������� ����� �Ǿ����ϴ�.\n");
		return;
   }
	
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
   			printf("%s", r[i]);
   }
   printf("\n===========================================================================\n");
}

void Out(char r[]){
   int s;
   printf("�ڸ��� �Է����ּ���.\n");
   scanf("%d", &s);
   r[s-1] == 0;
   return;
}

int Search(int desk){
   	if(a[(desk-1)==0])
   		return 1;
   	else return -1;
}
void Food(){
	
}
