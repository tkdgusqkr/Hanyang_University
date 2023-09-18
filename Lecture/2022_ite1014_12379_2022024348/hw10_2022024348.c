#include <stdio.h>
int main(void)
{
	int n;
	int m=0;
	printf("Input number : ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		m+=i;
	}
	printf("Sum of numbers : %d\n",m);
}
