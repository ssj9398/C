#include<stdio.h>

struct student
{
	int num;
	char name[20];
	int score[5];
	double avg;
};

struct student print_avg(struct student s1);
 
int main(void)
{
	struct student s1 = {315, "ȫ�浿",{82,93,74,90,65}};
	
	s1 = print_avg(s1)
	printf("���:%lf\n",s1.avg);
	return 0;		
		};
	
struct student print_avg(struct student s1)
{
	int i,sum = 0;
	
	printf("�й� :%d\n",s1.name);
	printf("�̸� : %s\n",s1.name);
	printf("�� �� :");
	for(i=0;i<5;i++)
	{
	
	printf("%5d",s1.score[i]);
	sum = sum+i;

}
printf("\n");
s1.avg = sum/5.0;
}
	
