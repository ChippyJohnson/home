#include<stdio.h>
#include<graphics.h>
int main()
{
    int gdriver=DETECT,gmode,errorcode;
    int i;

    initgraph(&gdriver,&gmode,"D:\Share\cglab");
    float x1,x2,y1,y2,dx,dy,xinc,yinc,step;
    printf("enter coordinates x1,x2,y1,y2\n");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    dx=x2-x1;
    dy=y2-y1;
    if(dx>dy)
        step=dx;
    else
        step=dy;
    xinc=dx/step;
    yinc=dy/step;

    for(i=0;i<step;i++)
    {
        x1=x1+xinc;
        y1=y1+yinc;
        delay(25);
        putpixel(x1,y1,1);
    }
    getch();
    return(0);
}


