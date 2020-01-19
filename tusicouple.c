#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
int xc=300,yc=200,r=75;
int x,y;
int M_PI=3.14;
void drawcircles()
{
    setcolor(GREEN);
    circle(x,y,r);
    circle(xc,yc,2*r);
}
int main()
{
    double angle=0,theta;
    int i,a;
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    a=xc+r;
    while(!kbhit())
    {
        while(a<=630)
        {
            theta=M_PI*angle/180;
            cleardevice();
            theta=M_PI*angle/180;
            x=xc+r*sin(theta);
            y=yc+r*cos(theta);
            angle+=20;
            drawcircles();
            delay(200);
        }
    }
    getch();

    return 0;
}

