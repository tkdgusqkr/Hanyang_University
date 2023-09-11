#include <stdio.h>
#include <string.h>
int main()
{
	char str1[500];
	scanf("%s",str1);
	printf("%s\n",str1);
	for (int i=0;i<strlen(str1)-1;i++)
	{	
		char str2[500];
		for (int j=0;j<strlen(str1)-1;j++)
		{
			str2[0]=str1[strlen(str1)-1];
			str2[j+1]=str1[j];
		}
		strcpy(str1,str2);
		printf("%s\n",str2);
	}
}
