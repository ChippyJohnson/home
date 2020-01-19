
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int xmax,ymax,xmin,ymin,m,xin,yin,one,n,arr[50],i;

void polyclip(int x1,int y1,int x2,int y2)
{
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
  //      printf("\nPress 1 to clip\n");
  //      scanf("%d",&one);
  //      cleardevice();
        rectangle(xmin,ymin,xmax,ymax);
        line(x1,y1,x2,y2);

    }
}
int main()
{

    int gdrive=DETECT,gmode,errorcode;
    initgraph(&gdrive,&gmode," ");
    printf("Enter coordinates of window\n");
    scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
    printf("\n Enter no of sides of polygon: ");
    scanf("%d",&n);
  //  drawpoly (int numpoints, int *polypoints);

    printf("\n Enter coordinates of polygon: ");
    for(i=0;i<(2*n);i++)
        scanf("%d",&arr[i]);

    rectangle(xmin,ymin,xmax,ymax);
/*    line(arr[0],arr[1],arr[2],arr[3]);
    line(arr[2],arr[3],arr[4],arr[5]);
    line(arr[4],arr[5],arr[6],arr[7]);
    line(arr[0],arr[1],arr[6],arr[7]);

    drawpoly(n,arr);
 */
    for(i=0;i<((2*n)-3);i+=2)
        line(arr[i],arr[i+1],arr[i+2],arr[i+3]);
    line(arr[0],arr[1],arr[(2*n)-2],arr[(2*n)-1]);

    printf("\nPress 1 to clip\n");
    scanf("%d",&one);
    cleardevice();
    for(i=0;i<((2*n)-3);i+=2)
    {
        polyclip(arr[i],arr[i+1],arr[i+2],arr[i+3]);
    }

    polyclip(arr[0],arr[1],arr[(2*n)-2],arr[(2*n)-1]);

    getch();
    return 0;
}

