#include<stdio.h>
#include<graphics.h>
int main()
{

    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"D:\Share\cglab");
    int x1,x2,y1,y2,x,y;

    printf("enter coordinates\n",x1,y1,x2,y2);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    printf("enter point coordinates\n");
    scanf("%d%d",&x,&y);
    if(x>x1 && x<x2 && y>y1 && y<y2)
    {
         rectangle(x1,y1,x2,y2);
         putpixel(x,y,2);
    }

    else
        printf("invalid");





    getch();
    return 0;
}

