#include <stdio.h>
#include "assert.h"
void bill(char* arg)
{
	int array[40];
        for(int i=0; i<40; i++)	array[i]=i;
	printf("bill: you passed %s\n", arg);
	fred(array);
}
