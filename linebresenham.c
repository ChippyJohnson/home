
#include<stdio.h>
#include<graphics.h>
int main()
{

    int gdriver=DETECT,gmode,errorcode;
    int k;
    initgraph(&gdriver,&gmode,"D:\Share\cglab");
    float x1,x2,y1,y2,dx,dy,xinc,yinc,step,temp,pk;
    printf("enter coordinates x1,x2,y1,y2\n");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

    if(x1>x2 && y1>y2)
    {
        temp=x1;
        x1=x2;
        x2=temp;

        temp=y1;
        y1=y2;
        y2=temp;
    }

    dx=x2-x1;
    dy=y2-y1;
    pk=(2*dy)-(2*dx);
    putpixel(x1,y1,4);
    for(k=0;k<dx;k++)
    {
        if(pk<0)
        {
            putpixel(++x1,y1,4);
            pk=pk+2*dy;
        }
        else
        {
            putpixel(++x1,++y1,4);
            pk=pk+2*dy-2*dx;
        }
        delay(25);
    }

    getch();
    return(0);
}


