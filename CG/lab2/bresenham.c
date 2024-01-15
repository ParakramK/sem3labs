#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
int main(){
	int x1,y1,x2,y2,i;
	float xk,yk,pk,dx,dy;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("enter left end point: \n");
	scanf("%d%d",&x1,&y1);
	printf("enter right end point: \n");
	scanf("%d%d",&x2,&y2);
	putpixel(x1,y1,WHITE);
	dx=x2-x1;
	dy=y2-y1;
	pk=2*dy-dx;
	xk=x1;
	yk=y1;
	for(i=0;i<=(dx-1);i++)	{
		delay(100);	
		if(pk<0)	{ 
			xk=xk+1;
			yk=yk;
			pk=pk+2*dy;
		}	else	{
			xk=xk+1;
			yk=yk+1;
			pk=pk+2*dy-2*dx;
		}
		putpixel(xk,yk,WHITE);
	}
	getch();
	return 0;
}