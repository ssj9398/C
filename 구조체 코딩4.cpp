#include<stdio.h>

struct student
{
	int id;
	char name[20];
	double grade;
};

int main(void)
{
	struct student s1= {123,"홍길동",4.1},
	               s2 = {123,"이길동",2.2},
				   s3 ={123,"김길동",3.3};
	
	struct student max;
	max= s1;
	if(s2.grade>max.grade) max = s2;
	if(s3.grade>max.grade) max = s3;
	
	printf("학번:%d\n",max.id);
	printf("이름:%s\n",max.name);
	printf("학점:%.1lf",max.grade);
	
	return 0; 
}
