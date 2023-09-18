#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int list[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	int List[n-2];
	for ( int j=0;j<n-2;j++)
	{
		List[j]=list[j]+list[j+1]+list[j+2];
	}
	int M=0;
	for (int k=0;k<n-2;k++)
	{
		if (M<=List[k])
		{
			M=List[k];
		}
	}
	printf("%d\n",M);
}
