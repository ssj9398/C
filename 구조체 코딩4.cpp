#include<stdio.h>

struct student
{
	int id;
	char name[20];
	double grade;
};

int main(void)
{
	struct student s1= {123,"ȫ�浿",4.1},
	               s2 = {123,"�̱浿",2.2},
				   s3 ={123,"��浿",3.3};
	
	struct student max;
	max= s1;
	if(s2.grade>max.grade) max = s2;
	if(s3.grade>max.grade) max = s3;
	
	printf("�й�:%d\n",max.id);
	printf("�̸�:%s\n",max.name);
	printf("����:%.1lf",max.grade);
	
	return 0; 
}
