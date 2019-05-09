#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  profile
{
	int age;
	double height;
};

struct student
{
	struct profile pf;
	int id;
	double grade;
};

int main(void)
{
	struct student yuni;
	yuni.id = 213222;
	yuni.grade =1.1;
	yuni.pf.age = 23;
	yuni.pf.height = 165.66;
	
	printf("id:%d\n",yuni.id);
	printf("grade:%.1lf\n",yuni.grade);
	printf("age:%d\n",yuni.pf.age);
	printf("height:%.1lf\n",yuni.pf.height);
	
}
	



