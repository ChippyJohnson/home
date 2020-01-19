#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode," ");
    float x1,y1,x2,y2,xfact,yfact,ang,rr,x,y,mx,my,xa,xb,ya,yb;
    int op;
    printf("enter the line coordinates(x1,y1) and (x2,y2): ");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
  //  printf("enter the option:\n\t1.translation\n\t2.scale\n\t3.rotation\t");
    while(1)
    {
        line(x1,y1,x2,y2);
        printf("enter the option:\n\t1.translation\n\t2.scale\n\t3.rotation\t");
        scanf("%d",&op);
        switch(op)
        {

        case 1:
            printf("enter the x and y translation factor: ");
            scanf("%f%f",&xfact,&yfact);
            /*  x1+=xfact;
              x2+=xfact;
              y1+=yfact;
              y2+=yfact;
              //cleardevice();
            */
            line(x1+xfact,y1+yfact,x2+xfact,y2+yfact);
            break;
        case 2:
            printf("enter the scaling factor: ");
            scanf("%f",&xfact);
            cleardevice();
            mx=(x1+x2)/2;
            my=(y1+y2)/2;
            xa=mx+(x1-mx)*xfact;
            ya=my+(y1-my)*xfact;
            xb=mx+(x2-mx)*xfact;
            yb=my+(y2-my)*xfact;
            line(xa,ya,xb,yb);
            break;
        case 3:
            printf("enter the angle of rotation: ");
            scanf("%f",&ang);
            rr=(3.14/180)*ang;
            x=x1+(cos(rr)*(x2-x1)-sin(rr)*(y2-y1));
            y=y1+(sin(rr)*(x2-x1)+cos(rr)*(y2-y1));
            line(x1,y1,x,y);
            break;
        default:
            printf("wrong entry");
        }
       // cleardevice();
    }
    getch();
    return 0;
}


