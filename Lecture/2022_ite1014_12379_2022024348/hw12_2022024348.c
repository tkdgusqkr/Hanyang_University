#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int list[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	for(int k=0;k<n;k++)
	{
		printf("%d ",list[k]);
	}
	int m=0;
	for(int j=0;j<n;j++)
	{
		if(m<=list[j])
		{
			m=list[j];
		}
	}
	printf("\n%d\n",m);
}
