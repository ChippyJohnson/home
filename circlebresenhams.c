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
    p1=3-2*r;
    while(x<y)
    {
            if(p1<0)
            {
                x++;
                p1=p1+4*x+6;
            }
            else
            {
                x++;
                y--;
                p1=p1+4*(x-y)+10;
            }
            putpixel(x1+x,y1-y,1);
            putpixel(x1+y,y1-x,2);
            putpixel(x1+y,y1+x,3);
            putpixel(x1-y,y1-x,4);
            putpixel(x1-x,y1+y,5);
            putpixel(x1+x,y1+y,6);
            putpixel(x1-x,y1-y,7);
            putpixel(x1-y,y1+x,8);

    }
    getch();
    return 0;
}


