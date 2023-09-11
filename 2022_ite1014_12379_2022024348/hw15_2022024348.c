#include <stdio.h>
double mysqrt(double y)
{
	double x=1.0;
	for (int i=0;i<1000;i++)
	{
		if ((x-y/x)<0.000000000000001 && (x-y/x)>-0.000000000000001)
		{
			break;
		}
		x=(x+y/x)/2;
	}
	return x;
}
int main()
{
	double y;
	while(1)
	{	
		scanf("%lf",&y);
		if (y>=0)
		{
			printf("%.5f\n",mysqrt(y));
		}
		else
		{	
			printf("error");
		}
	}
}
