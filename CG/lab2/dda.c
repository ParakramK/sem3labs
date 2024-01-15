#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <conio.h>
 
void lineDDA(int x1, int y1,int x2, int y2){
	int i,steps, dx,dy;
	float xinc,yinc,x,y;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=dx/steps;
	yinc=dy/steps;

	x=x1;
	y=y1;
	for(i=0;i<steps;i++){
		putpixel(x,y,WHITE);
		x+=xinc;
		y+=yinc;
		delay(10);		
	}	
}

void main( ){
	int gd=DETECT,gm; 
	initgraph(&gd,&gm,"c:\\turboc3\\bgi"); 
	lineDDA(100,100,350,350);
	getch();	 
	closegraph();
}