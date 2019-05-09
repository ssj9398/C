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
	struct student s1 = {315, "홍길동",{82,93,74,90,65}};
	
	s1 = print_avg(s1)
	printf("평균:%lf\n",s1.avg);
	return 0;		
		};
	
struct student print_avg(struct student s1)
{
	int i,sum = 0;
	
	printf("학번 :%d\n",s1.name);
	printf("이름 : %s\n",s1.name);
	printf("점 수 :");
	for(i=0;i<5;i++)
	{
	
	printf("%5d",s1.score[i]);
	sum = sum+i;

}
printf("\n");
s1.avg = sum/5.0;
}
	
