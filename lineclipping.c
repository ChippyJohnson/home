#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{

    int gdrive=DETECT,gmode,errorcode;
    initgraph(&gdrive,&gmode," ");
    int xmax,ymax,xmin,ymin,x1,y1,x2,y2,m,xin,yin,one;
    printf("Enter coordinates of window\n");
    scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
    printf("\n Enter coordinates of line\n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    rectangle(xmin,ymin,xmax,ymax);
    line(x1,y1,x2,y2);
    if(x1<xmin&&x2<xmin||x1>xmax&&x2>xmax||y1<ymin&&y2<ymin||y1>ymax&&y2>ymax)
    {
        rectangle(xmin,ymin,xmax,ymax);
    }
    else
    {
        m=(y2-y1)/(x2-x1);
        if(x1<xmin)
        {
            y1=y1+(xmin-x1)*m;
            x1=xmin;
        }
        if(x2<xmin)
        {
            y2=y2+(xmin-x2)*m;
            x2=xmin;
        }
        if(x1>xmax)
        {
            y1=y1+(xmax-x1)*m;
            x1=xmax;
        }
        if(x2>xmax)
        {
            y2=y2+(xmax-x2)*m;
            x2=xmax;
        }
        if(y1<ymin)
        {
            x1=x1+((ymin-y1)/m);
            y1=ymin;
        }
        if(y2<ymin)
        {
            x2=x2+((ymin-y2)/m);
            y2=ymin;
        }
        if(y1>ymax)
        {
            x1=x1+((ymax-y1)/m);
            y1=ymax;
        }
        if(y2>ymax)
        {
            x2=x2+((ymax-y2)/m);
            y2=ymax;
        }
        printf("\nPress 1 to clip\n");
        scanf("%d",&one);
        cleardevice();
        rectangle(xmin,ymin,xmax,ymax);
        line(x1,y1,x2,y2);

    }
    getch();
    return 0;
}

