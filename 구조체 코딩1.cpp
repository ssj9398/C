#include<stdio.h>

struct student
{
	int num;
	double grade;
};

int main(void)
{
	struct student s1;
	s1.num = 132132;
	s1.grade = 1.2;
	printf("�й� : %d=n",s1.num);
	printf("�� ��:%.1lf",s1.grade);
	
	return 0;

}  
