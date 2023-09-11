#include <stdio.h>
int main()
{
	struct Person{
		char name[11];
		int age;
	};
	struct Person person[3];
	for(int i=0;i<3;i++)
	{
		scanf("%s%d",person[i].name,&person[i].age);
	}
	for(int i=0;i<3;i++)
	{
		printf("Name:%s, Age:%d\n",person[i].name,person[i].age);
	}
}
