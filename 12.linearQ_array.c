#include<stdio.h>
void ins(int que[],int *f,int *b)
{
    int elem,index;
    ///check overflow
    if(*b==3-1)
        printf("Queue is FULL!!!");
    else
    {
//        *f=*f+1;
        *b=*b+1;
        printf("enter the element: ");
        scanf("%d",&elem);
        index=*b;
        que[index]=elem;
    }
}
void display(int que[],int f,int b)
{
    int p;
    if(f==-1||f==b+1)
        printf("QUEUE EMPTY!\n");
    else
    {
        printf("\nQueue is:-\n\t");
        for(p=f;p<=b;p++)
            printf("%5d",que[p]);
    }
}
int isempty(int f,int b)
{
    if(f==-1||f==b+1)
        return 1;
    else
        return 0;
}
int del(int que[],int *f,int *b)
{
    *f=*f+1;
        display(que,f,b);
}
void main()
{
    int que[5],f=-1,b=-1,opt,elem;
    while(1)
    {
        printf("\nMenu:\n\t1.INSERT\n\t2.DELETE\n\t3.EXIT\n");
        printf("Enter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                if(f==-1)
                    f++;
                ins(que,&f,&b);
                display(que,&f,&b);
                break;
            case 2:
                if(!isempty(f,b))
                {
                    elem=del(que,&f,&b);
                    printf("The deleted element is %d",elem);
                }
                else
                    printf("Deletion not possible! ");
                display(que,f,b);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Wrong entry");
        }
    }



}
