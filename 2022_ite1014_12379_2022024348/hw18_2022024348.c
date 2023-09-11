#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char *arr1[5001];
	char *arr2[3]={",","?","!"};
	char str[5001];
	scanf("%[^\n]s",str);
	int g=0;
	char *ptr=strtok(str," ");
	for(int i=0;ptr!=NULL;i++)
	{
		arr1[i]=malloc(strlen(ptr)*sizeof(char));
		strcpy(arr1[i],ptr);
		g=g+1;
		ptr=strtok(NULL," ");
	}
	for(int j=0;j<g;j++)
	{
		int m=0;
		int n=0;
		if(strcmp(arr1[j],arr2[0])==0 || strcmp(arr1[j],arr2[1])==0 || strcmp(arr1[j],arr2[2])==0)
		{
			continue;
		}
		else
		{
			printf("%s ",arr1[j]);
			for(int k=0;k<g;k++)
			{
				if(strcmp(arr1[j],arr1[k])==0)
				{
					m=m+1;
					if(n>0)
					{
						strcpy(arr1[k],arr2[1]);
					}
					n=n+1;
				}
			}
			printf("%d\n",m);
		}
	}
}
