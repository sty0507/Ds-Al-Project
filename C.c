#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM 10

//������ 1) show �Լ��� �׳� �ٷ� ���� 
// 2) name�� ����� �ȵ�-���� NULL�� ���. 

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
	}
}
void Register(struct Person r[]){
   	int desk=0, i, j;
   	char name[20];
   	printf("�ڸ��� �̸��� �Է��ϼ���(���� ����)\n");
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
   		strcpy(r[k].name, name);
   		strcpy(r[k].li, 1);
		printf("���������� ����� �Ǿ����ϴ�.\n");
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
   printf("�ڸ��� �Է����ּ���.\n");
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
		printf("1.��� 2.���� 3.����");
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
