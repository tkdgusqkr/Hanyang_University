#include <iostream>
#include "sumdiff.h"
using namespace std;
int main(int argc,char **argv)
{
	int a=stoi(argv[1]);
	int b=stoi(argv[2]);
	int sum,diff;
	getSumDiff(a,b,sum,diff);
	cout<<"sum: "<<sum<<"\ndiff: "<<diff;
}
