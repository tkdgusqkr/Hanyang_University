#include <iostream>
#include <string>
using namespace std;
int main(int argc,char **argv)
{
	for(int i=0;i<stoi(argv[argc-1]);++i)
	{
		printf("%s\n",argv[1]);
	}
}
