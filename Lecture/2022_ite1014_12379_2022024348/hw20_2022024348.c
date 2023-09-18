#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int list1[n*3];
	for(int i=0;i<n*3;i++)
	{
		scanf("%d",&list1[i]);
	}
	int list2[n];
	for(int j=0;j<n;j++)
	{
		list2[j]=(list1[j*3]+list1[j*3+1]+list1[j*3+2])/3;
	}
	int list3[n];
	for(int h=0;h<n;h++)
	{
		list3[h]=-1;
	}
	int m=0;
	for(int t=0;t<n;t++)
	{
		for(int g=0;g<n;g++)
		{
			if(list3[m]<=list2[g])
			{
				list3[m]=list2[g];
			}
		}
		int d=0;
		for(int f=0;f<n;f++)
		{
			if(list2[f]==list3[m])
			{
				list2[f]=-2;
				d=d+1;
			}
		}
		for(int s=0;s<d;s++)
		{
			list3[m+s]=list3[m];
		}
		m=m+d;
		t=t+d-1;
	}
	for(int r=0;r<n;r++)
	{
		printf("%d등 성적의 평균 : %d\n",r+1,list3[r]);
	}
	return 0;
}
