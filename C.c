#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM 10

//������ 1) show �Լ��� �׳� �ٷ� ���� 
// 2) name�� ����� �ȵ�-���� NULL�� ���. 

struct Person{
	char name[10];
	char li[1];
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
   	int i, j, desk=0;
   	char name[20];
   	printf("�ڸ��� �Է��ϼ���(���ڸ�)\n");
   	scanf("%d", &desk);
   	printf("�̸��� �Է��ϼ���(���� ����, ���ڸ�)\n");
   	scanf("%s", &name);
   	
   	
   	//���� Ȯ�� �ڵ� 
   	if(desk==0  || desk >10){
   		printf("Error\n");
   		return;
   	}
	
   	//������ �ڸ��� ����� �ִ��� ��
   	int result = Search(desk); 
   	if(result==1){
   		return; 
   	}
   	else{
   		strcpy(r[k].name, name);
   		strcpy(r[k].li, "1");
		printf("���������� ����� �Ǿ����ϴ�.\n");
		k++;
		return;
   }
	
}

void Show(struct Person r[]){
   	int j;
//   	printf("===========================================================================\n");
//	printf("    1      2      3      4      5      6      7      8      9      10\n");
//	printf("---------------------------------------------------------------------------\n");
//  	for(j=0; j<10;j++){
//   		if(r[j].li == "0")
//   			printf("   NULL");
//   		else
//   			printf("%s", r[j].name);
//   }
//   printf("\n===========================================================================\n");

	for(j=0; j<10; j++){
		printf("%d�� �ڸ� : %s\n", j+1, r[j].name);
	}
}

void Out(struct Person r[]){
   int s;
   printf("�ڸ��� �Է����ּ���.\n");
   scanf("%d", &s);
   r[s-1].name == "NULL";
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
