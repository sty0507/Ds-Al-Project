#include <stdio.h>
#include <string.h>
struct Person{
	char name[10];
	char li[10];
};

int main()
{
	struct Person n[5];
	int i;
	for(i=0;i<5;i++){
		strcpy(n[i].li, "0");
	}
	for(i=0; i<5;i++){
		printf("%s\n", n[i].li);
	}
}
