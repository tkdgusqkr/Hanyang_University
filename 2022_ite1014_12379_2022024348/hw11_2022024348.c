#include <stdio.h>
void ku(int x);
int main(void)
{
	int a;
	scanf("%d",&a);
	ku(a);
}
void ku(int x)
{
	if(x>=1 && x<=9)
	{
		printf("%d단\n",x);
		for(int y=1;y<=9;y++)
		{
			printf("%d*%d = %d\n",x,y,x*y);
		}
	}
	else
	{
		printf("잘못된 입력범위입니다.\n");
	}
}


