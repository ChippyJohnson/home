#include<stdio.h>
void ins(int que[],int *f,int *b)
{
    if((*b+1)%4==*f && *b!=-1)              ///check for overflow
        printf("\n Queue is full");
    else
    {
        int elem;
        *b=(*b+1)%4;                       ///increment back
        printf("\nEnter the element: ");
        scanf("%d",&elem);
        que[*b]=elem;                       ///add element at back;
    }
}
void display(int que[],int f,int b)
{
    int c;
    if(f==-1)
        printf("EMPTY QUEUE");
    else
    {
        for(c=f; c!=b; c=(c+1)%4)
            printf("%5d",que[c]);
        printf("%5d",que[c]);
    }

}
int del(int que[],int *f,int *b)
{
    int num;
    num=*f;
    if(*f==(*b))     ///if queue with one element, set front=back=-1
        *f=*b=-1;
    else
        (*f)=(*f+1)%4;  ///else increment front
    return(num);
}
int isempty(int f)
{
    if(f==-1)
        return 1;
    return 0;
}
void main()
{
    int que[4],f=-1,b=-1,opt,n=-1;
    while(1)
    {
        printf("\nMenu:\n\t1.INSERT\n\t2.DELETE\n\t3.EXIT\n");
        printf("Enter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            if(f==-1)
                f++;            ///if queue is empty, increment front
            ins(que,&f,&b);
            display(que,f,b);
            break;
        case 2:
            if(!isempty(f))     ///check for underflow
            {
                n=del(que,&f,&b);
                printf("\tdeleted element is :%d\n",que[n]);
            }
            else
                printf("Cannot be deleted ");
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

