#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct profile
{
	char name[20];
	int age;
	double height;
	char *intro;
};

int main(void)
{
	struct profile yuni;
	
	strcpy(yuni.name,"������");
	yuni.age = 23;
	yuni.height = 165.6;
	yuni.intro = (char*) malloc(80);
	printf("�ڱ�Ұ���:");
	fgets(yuni.intro,80,stdin);
	
	printf("�̸� : %s\n",yuni.name);
	printf("���� : %d\n",yuni.age);
	printf("Ű : %.1lf\n",yuni.height);
	printf("�ڱ�Ұ� :%s",yuni.intro);
	
	return 0;  
}
