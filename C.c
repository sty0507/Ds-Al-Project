#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//������ 1) show �Լ��� �׳� �ٷ� ���� 
// 2) name�� ����� �ȵ�-���� NULL�� ���. 
  
char a[10]={0,0,0,0,0,0,0,0,0,0};
void Register(char a[]);
void Show(char a[]);
void Out();
int main(){
	int i, j;
   int n;
   printf("1.��� 2.�ڸ����� 3. �ڸ����� 4.���α׷� ����\n");
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
   	printf("�ڸ��� �̸��� �Է��ϼ���\n");
   	scanf("%d %s", &desk, &name);
   	
   	if(desk==0 || desk >10){
   		printf("Error\n");
   		return;
   }
   
   	if(isdigit(name)!=0){
   		printf("���ڸ� �Է��ϼ̽��ϴ�.\n");
   		return;
	   }
	   
   	int result = Search(desk);
   	
   	if(result){
   		return;
   }
	a[(desk-1)] = name;
	printf("���������� ����� �Ǿ����ϴ�.\n");
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
