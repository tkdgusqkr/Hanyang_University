#include <stdio.h>
typedef struct
{
	int xpos;
	int ypos;
}Point;
Point getScale2xPoint(const Point* p)
{
	Point P;
	P.xpos=p->xpos*2;
	P.ypos=p->ypos*2;
	return P;
}
void swapPoints(Point* p1, Point* p2)
{
	Point P;
	P=*p1;
	*p1=*p2;
	*p2=P;	
}
int main(void)
{
	Point p1,p2;
	scanf("%d%d",&p1.xpos,&p1.ypos);
	p2=getScale2xPoint(&p1);
	printf("Calling getScale2xPoint()\np1 : %d %d\np2 : %d %d\n",p1.xpos,p1.ypos,p2.xpos,p2.ypos);
	swapPoints(&p1,&p2);
	printf("Calling swapPoint()\np1 : %d %d\np2 : %d %d\n",p1.xpos,p1.ypos,p2.xpos,p2.ypos);
}
