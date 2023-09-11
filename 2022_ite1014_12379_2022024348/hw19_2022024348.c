#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n];
	int c[n];
	int m=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	b[0]=a[0];
	c[0]=0;
	for(int j=0;j<n;j++)
	{
		if(b[m]<a[j])
		{
			b[m+1]=a[j];
			m++;
			if(j>0)
			{
				c[j]=m;
			}
		}
		else
		{
			for(int k=0;k<=m;k++)
			{
				if(a[j]<=b[k])
				{
					b[k]=a[j];
					c[j]=k;
					break;
				}
			}
		}
	}
	printf("%d\n",m+1);
	int d[n];
	int p=-1;
	for(int g=0;g<=m;g++)
	{
		for(int s=0;s<n;s++)
		{
			d[s]=-2;
		}
		if(p==-1)
		{
			for(int h=0;h<n;h++)
			{
				if(c[h]==m-g)
				{
					b[m-g]=a[h];
					d[h]=h;
				}
			}
		}
		else
		{
			for(int h=0;h<n;h++)
			{
				if(c[h]==m-g && h<=p)
				{
					b[m-g]=a[h];
					d[h]=h;
				}
			}
		}
		p=-1;
		for(int q=0;q<n;q++)
		{
			if(d[q]!=-2 && d[q]>=p)
			{
				p=d[q];
			}
		}
	}
	for(int f=0;f<=m;f++)
	{
		printf("%d ",b[f]);
	}
	printf("\n");
	return 0;
}
