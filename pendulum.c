
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{

    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"D:\Share\cglab");
    float x,y,x1=300,x2=300,y1=100,y2=300,ang=240;
    double rr;
    while(!kbhit())
    {
        cleardevice();
        rr=(3.14/180)*ang;
        x=x1+cos(rr)*(x2-x1)+sin(rr)*(y2-y1);
        y=y1+sin(rr)*(x2-x1)-cos(rr)*(y2-y1);
        line(x1,y1,x,y);
        circle(x,y,6);
        fillellipse(x,y,10,10);
        delay(50);
        ang-=3;
        if(ang<120)
        {
            while(ang<240)
            {
                cleardevice();
                rr=(3.14/180)*ang;
                x=x1+cos(rr)*(x2-x1)+sin(rr)*(y2-y1);
                y=y1+sin(rr)*(x2-x1)-cos(rr)*(y2-y1);
                line(x1,y1,x,y);
                circle(x,y,6);
                fillellipse(x,y,10,10);
                delay(50);
                ang+=3;
            }
        }
    }
    getch();
    return 0;
}
