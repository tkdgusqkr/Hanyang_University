#include <stdio.h>
int main()
{
    int n;
    int min=100;
    scanf("%d",&n);
    if (n>=0)
    {
        int list[n];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&list[i]);
        }
        for (int j=0;j<n;j++)
        {
            if (min>=list[j])
            {
                min=list[j];
            }
        }
        printf("%d ",min);
        while(1)
        {
		int min2=101;
            for (int k=0;k<n;k++)
            {
                if (min<list[k] && min2>=list[k])
                {
                    min2=list[k];
                }
            }
	    if (min2==101)
	    {
		    break;
	    }
            printf("%d ",min2);
	    min=min2;
        }
    }
    else
    {
        printf("error");
    }
	printf("\n");    
}
