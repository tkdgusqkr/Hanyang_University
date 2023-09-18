#include <iostream>
using namespace std;
int N;
void magicSquare(int **square,int n)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			square[i][j]=0;
		}
	}
	int y=0;
	int x=n/2;
	int ny,nx;
	for(int i=1;i<=n*n;++i)
	{
		if(square[y][x]>0)
		{
			y=++ny;
			x=nx;
			if(y>=n)
			{
				y=0;
			}
		}
		square[y][x]=i;
		ny=y;
		nx=x;
		--y;
		++x;
		if(y<0)
		{
			y=n-1;
		}
		if(x>=n)
		{
			x=0;
		}
	}
}
int main()
{
	cin>>N;
	int **Square=new int*[N];
	for(int i=0;i<N;++i)
	{
		Square[i]=new int[N];
	}
	magicSquare(Square,N);
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cout<<Square[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
