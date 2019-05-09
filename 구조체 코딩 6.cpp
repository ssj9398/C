#include<stdio.h>

struct profile
{
	char name[20];
	double grade;
	int english;	
};
void input_data(struct profile *ps);
void elite(struct profile *ps);
int main(void)
{
	struct profile new_staff[5];
	
	input_data(new_staff);
	elite(new_staff);
	
	return 0;
}

void input_data(struct profile *ps)
{
	int i;
	for(i = 0; i<5; i++){
	
	scanf("%s%lf%d",(ps+i)->name,&((ps+i)->grade),&((ps+i)->english));
}
}
void elite(struct profile *ps)
{
	int i;
	for(i=0;i<5;i++){
	
	if(((ps+i)->grade>=4.0) && ((ps+i)->english>=900)){
	
	printf("%s%lf%d",(ps+i)->name,(ps+i)->grade,(ps+i)->english);}
}
}
