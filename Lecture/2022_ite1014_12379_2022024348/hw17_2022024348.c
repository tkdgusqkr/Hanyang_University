#include <stdio.h>
int main()
{
	int s[100000];
	int n;
	int i;
	int j=0;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			if(j!=0)
			{	
				printf("%d\n",j);
				printf("%d\n",s[j-1]);
				for(int k=0;k<j;j--)
				{
					printf("%d ",s[j-1]);
				}

			}
			else
			{
				printf("%d",j);
			}
			printf("\n");
			break;
		}
		else if(n==1)
		{
			scanf("%d",&i);
			s[j]=i;
			j=j+1;
		}
		else if(n==2)
		{
			if(j==0)
			{
				j=j;
			}
			else
			{
				j=j-1;
			}
		}
	}
}
