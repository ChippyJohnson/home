#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
int main()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");

    int xmin,ymin,xmax,ymax,sides,i,x1,x2,y1,y2,size=-1,arr[20],k,m,ch;

    printf("\nenter the cordinates of window: ");
    scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
    rectangle(xmin,ymin,xmax,ymax);

    printf("Enter the no of sides :");
    scanf("%d",&sides);
    for(i=1;i<=sides;i++)
    {
        printf("Enter the cordinates of sides %d:",i);
        for(k=0;k<4;k++)
        {
            size++;
            scanf("%d",&arr[size]);
        }
    }

    //line drawing
    for(k=0;k<=size;)
    {
        x1=arr[k++];
        y1=arr[k++];
        x2=arr[k++];
        y2=arr[k++];
        line(x1,y1,x2,y2);
    }

    //clipping
    printf("Do you want to clip(1/0): ");
    scanf("%d",&ch);
    if(ch==1)
    {
    cleardevice();
    rectangle(xmin,ymin,xmax,ymax);
    for(k=0;k<=size;)
    {
        x1=arr[k++];
        y1=arr[k++];
        x2=arr[k++];
        y2=arr[k++];
        if((x1<xmin)&&(x2<xmin)||(x1>xmax)&&(x2>xmax)||(y1<ymin)&&(y2<ymin)||(y1>ymax)&&(y2>ymax));
        else
        {

        if(x1<xmin)
        {
            m=(y2-y1)/(x2-x1);
            y1=y1+(xmin-x1)*m;
            x1=xmin;
        }
        if(x2<xmin)
        {
            m=(y2-y1)/(x2-x1);
            y2=y2+(xmin-x2)*m;
            x2=xmin;
        }
        if(x1>xmax)
        {
            m=(y2-y1)/(x2-x1);
            y1=y1+(xmax-x1)*m;
            x1=xmax;
        }
        if(x2>xmax)
        {
            m=(y2-y1)/(x2-x1);
            y2=y2+(xmax-x2)*m;
            x2=xmax;
        }
        if(y1<ymin)
        {
            m=(y2-y1)/(x2-x1);
            x1=x1+((ymin-y1)/m);
            y1=ymin;
        }
        if(y2<ymin)
        {
            m=(y2-y1)/(x2-x1);
            x2=x2+((ymin-y2)/m);
            y2=ymin;
        }
        if(y1>ymax)
        {
            m=(y2-y1)/(x2-x1);
            x1=x1+((ymax-y1)/m);
            y1=ymax;
        }
        if(y2>ymax)
        {
            m=(y2-y1)/(x2-x1);
            x2=x2+((ymax-y2)/m)-1;
            y2=ymax;
        }

        line(x1,y1,x2,y2);
    }
    }
    }

getch();
}

