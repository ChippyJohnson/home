/*
#include<math.h>
#define Round(val)((int)(val+.5))*/
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    float a;
    int xa,xb,ya,yb,ch,t,x,y;
    printf("Enter the cordinates of line : ");
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    line(xa,ya,xb,yb);
    do
    {
    printf("Enter the opertion:\n 1.Rotation\n2.Scaling\n3.Translation\n4.exit\n:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Enter angle to rotate:");
            scanf("%d",&t);
            cleardevice();
            a=(3.14/180)*t;
            x=xa+cos(a)*(xb-xa)+sin(a)*(yb-ya);
            y=ya+sin(a)*(xb-xa)-cos(a)*(yb-ya);
            xb=x;
            yb=y;
            line(xa,ya,xb,yb);
            break;
        case 2:
            printf("Enter length to scale:");
            scanf("%d",&t);
            cleardevice();
            if(ya==yb)
                line(xa-t,ya,xb+t,yb);
            else
                line(xa-t,ya-t,xb+t,yb+t);
            break;
        case 3:
            printf("Enter value to translate:");
            scanf("%d",&t);
            cleardevice();
            line(xa+t,ya,xb+t,yb);
            break;
        case 4:
            exit(0);
        default:
            printf("not valid");
            break;
    }
    }while(1);
    getch();
}
