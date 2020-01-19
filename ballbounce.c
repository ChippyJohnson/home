#include<stdio.h>
#include<graphics.h>
int main()
{
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode," ");
    float i,j,r=6,c1=200,c2=100,x1=100,y1=250,x2=800,y2=250;
    circle(c1,c2,r);
    line(x1,y1,x2,y2);
    i=x1,j=c1;
    while(1)
    {

        for(; i<(y2-(r/2)); i++,j=j+0.5)
        {
            cleardevice();
            circle(j,i,r);
            line(x1,y1,x2,y2);

            delay(5);

        }
        for(i=(y2-(r/2)); i>c2; i--,j=j+0.5)
        {
            cleardevice();
            circle(j,i,r);
//           fillellipse(300,j,10,100);
            line(x1,y1,x2,y2);

            delay(5);


        }
    }
    getch();
    return 0;
}

