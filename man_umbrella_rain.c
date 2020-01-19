#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void displayMan(int x,int y)
{
    circle(x,y,10);         //face
    line(x,y+10,x,y+30);        //neck
    line(x,y+30,x-20,y+40);    //left hand
    line(x,y+30,x+20,y+40);    //right hand
    line(x+20,y+40,x+30,y+30);
    line(x,y+30,x,y+70);        //body
    line(x+30,y+30,x+30,y-90);  //umbrella
    pieslice(x+30,y-30,0,180,55);

    line(x,y+70,x-20,y+90);//left leg
    line(x,y+70,x+20,y+90);//right

}
int main()
{
    int gd=DETECT, gm,i,d=0,x=50,y=340,shouldMove=1;
    int rx,ry;
    initgraph(&gd,&gm," ");
    while(1)
    {
        cleardevice();
        displayMan(x,340);
        line(0,430,639,430);

        for(i=0;i<500;i++)
        {
            rx=rand()%800;
            ry=rand()%600;
            /*rx=rand()%639;
            ry=rand()%439;
           */ if(rx>=(x-40)&&rx<=(x+110))
                if(ry>=(y-50)&&ry<=479)
                    continue;
            line(rx-3,ry+3,rx,ry);
        }

        //legs
   /*     if(shouldMove)
        {
            if(d<20)
                d+=10;
            else
                shouldMove=0;
            line(x,y+70,x-d,y+90);//left
            line(x,y+70,x+d,y+90);//right
        }
        else
        {
            if(d>0)
                d-=10;
            else
                shouldMove=1;
            line(x,y+70,x-d,y+90);
            line(x,y+70,x+d,y+90);
        }
*/

        delay(200);
        x=(x+10)%639;
    }
    getch();
    return 0;
}
