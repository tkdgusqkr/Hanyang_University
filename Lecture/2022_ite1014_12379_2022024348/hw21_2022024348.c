#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
	double *_ptr;
	int M;
	int N;
};
double get(struct Matrix *mat,int i,int j)
{
	return mat->_ptr[i*mat->N+j];
}
void set(struct Matrix *mat,int i,int j,double d)
{
	mat->_ptr[i*mat->N+j]=d;
}
int main()
{
	struct Matrix *matrix=(struct Matrix *)malloc(sizeof(struct Matrix));
	scanf("%d%d",&(matrix->M),&(matrix->N));
	double *ptr=(double *)malloc(sizeof(double)*((matrix->M)*(matrix->N)));
	matrix->_ptr=ptr;
	double d;
	for(int i=0;i<(matrix->M);i++)
	{
		for(int j=0;j<(matrix->N);j++)
		{
			scanf("%lf",&d);
			set(matrix,i,j,d);
		}
	}
	printf("%d %d\n",matrix->M,matrix->N);
	for(int i=0;i<(matrix->M);i++)
	{
		for(int j=0;j<(matrix->N);j++)
		{
			printf("%g ",get(matrix,i,j));
		}
		printf("\n");
	}
	free(matrix);
	free(ptr);
	return 0;
}
