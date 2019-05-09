#include <stdio.h>

int pn(int p)
{
	int sum = 0, x = 2, y;
	while (1){
		y=2;
		while(x%y!=0)
		y++;
		if(x==y)
		sum+=x;
		if(x<p)
		x++;
		else 
		break;
	}
	return sum;
	
}
void re(int *r){
	int i =1;
	while(i<5){
		i++;
		*r=*r+pn(i);
	}
}
main()
{
	int a=0;
	int*result = &a;
	re(result);
	printf("%d",a);
 } 
