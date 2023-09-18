#include <stdio.h>
void rotateLeft(int* pa, int* pb, int* pc)
{
	int tmp=*pa;
	*pa=*pb;
	*pb=*pc;
	*pc=tmp;
}
void rotateRight(int* pa, int* pb, int* pc)
{
	int tmp=*pc;
	*pc=*pb;
	*pb=*pa;
	*pa=tmp;
}
int main(void)
{
	int a=10,b=20,c=30;
	int i;
	while(1)
	{
		printf("%d:%d:%d\n",a,b,c);
		scanf("%d",&i);
		if(i==1)
		{
			rotateLeft(&a,&b,&c);
		}
		else if(i==2)
		{
			rotateRight(&a,&b,&c);
		}
		else
		{
			break;
		}
	}	
}
