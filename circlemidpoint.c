#include<stdio.h>
#include<graphics.h>
int main()
{
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"D:\Share\cglab");
    float x1,y1,p1,p2,x,y,k,r,p0;
    printf("Enter the radius");
    scanf("%f",&r);
    printf("Enter the circle cordinates");

    scanf("%f %f",&x1,&y1);
    x=0;y=r;
    putpixel(x+x1,y+y1,5);
    p1=5/4-r;
    while(x<y)
    {
        for(k=0;k<7;k++)
        {
            if(p1<0)
            {
                x++;
                p2=p1+2*x+3;
                p1=p2;
            }
            else
            {
                x++;
                y--;
                p0=p1+2*x+1-2*y;
                p1=p0;

            }
            putpixel(x+x1,y+y1,5);
            putpixel(-x+x1,y+y1,5);
            putpixel(x+x1,-y+y1,5);
            putpixel(-x+x1,-y+y1,5);
            putpixel(x1+y,y1+x,5);
            putpixel(x1-y,y1+x,5);
            putpixel(x1+y,y1-x,5);
            putpixel(x1-y,y1-x,5);
        }
    }
    getch();
    return 0;
}

