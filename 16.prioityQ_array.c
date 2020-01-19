#include<stdio.h>
#define prior 5
#define col 3
void ins(int que[][col],int fb[][2],int p)
{
    if((fb[p][1]+1)%col==fb[p][0] && fb[p][1]!=-1)      ///check Q full
        printf("\nCannot Insert.Queue is FULL!\n");
    else
    {
        fb[p][1]=(fb[p][1]+1)%col;                      ///increment back
        printf("\nEnter the element: ");
        scanf("%d",&que[p][fb[p][1]]);                  ///add element at back
    }
}
int del(int fb[][2],int que[][col])
{
    int num,p;
    for(p=1;p<prior;p++)            ///finding the 1st non empty priority
        if(fb[p][0]!=-1)
            break;
    num=que[p][(fb[p][0])];
    if(fb[p][0]==fb[p][1])          ///if front = back, f=b=-1 (if only one elem)
        fb[p][0]=fb[p][1]=-1;
    else
        fb[p][0]=(fb[p][0]+1)%col;  ///else increment front
    return(num);
}

void display(int fb[][2],int que[][col])
{
    int r,c;
    printf("queue is ...\nPRIORITY  F   B\n");
    for(r=1; r<prior; r++)
    {
        printf("%4d%7d%4d",r,fb[r][0],fb[r][1]);  ///print front and back
        if(fb[r][0]!=-1)
        {
            for(c=fb[r][0]; c!=fb[r][1]+1; c=(c+1)%col)   ///print queue
                printf("%5d",que[r][c]);
        //if(c!=-1)
           // printf("%5d",que[r][c]);                ///print element at the back(the last element)
        }
        printf("\n");
    }
}
int isempty(int fb[][2])
{
    int p,c=0;
    for(p=1;p<prior;p++)
        if(fb[p][0]==-1)
            ++c;
    if(c==prior-1)
        return 1;
    return 0;
}
void  main()
{
    int que[prior][col],opt,p,r,c,fb[prior][2],n;
    for(r=1; r<prior; r++)
        for(c=0; c<2; c++)
            fb[r][c]=-1;
    display(fb,que);
    for(;;)
    {
        printf("MENU:\n\t1.INSERT\n\t2.DELETE\n\t0.EXIT");
        printf("\n\tenter option: ");
        scanf("%d",&opt);
        if(opt<1)
            break;
        else
        {
            switch(opt)
            {
            case 1:
                printf("Enter the priority: ");
                scanf("%d",&p);
                if(p>=1 && p<prior)             ///checking the availability of concerned priority
                {
                    if(fb[p][0]==-1)
                        fb[p][0]++;             ///incrementing front @ begining
                    ins(que,fb,p);
                }
                else
                    printf("\n PRIORITY DOESNOT EXIST!...");
                display(fb,que);
                break;
            case 2:
                if(!isempty(fb))                ///checking for underflow
                {
                    n=del(fb,que);
                    printf("\n\tThe deleted element is %d\n",n);
                }
                else
                    printf("Queue empty!\n");
                display(fb,que);
                break;
            case 0:
                exit(0);
            default:
                printf("wrong entry");
            }
        }
    }
}
