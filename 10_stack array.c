#include<stdio.h>
#define cap 3
void push(int stack[],int *tp)///call by reference
{
    int elem;
    if(*tp==cap-1)              ///check for overflow
        printf("CAN'T PUSH, STACK OVERFLOW!");
    else
    {
        printf("enter the element: ");
        scanf("%d",&elem);
        *tp=*tp+1;              ///increment top
        stack[*tp]=elem;        ///input element
    }
}
int isempty(int top)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int pop(int stack[],int *tp)
{
    int elem;
    elem=stack[*tp];
    *tp=*tp-1;           ///decrement top
    return elem;
}
void display(int stack[],int top)
{
    int sp;
    if(top==-1)
        printf("STACK EMPTY!\n");
    else
    {
        printf("\n\tStack is:-\n");
        for(sp=top; sp>=0; sp--)
            printf("%20d\n",stack[sp]);
    }
}
void main()
{
    int stack[cap],s,top=-1,opt,elem;
    char ch;
    while(1)
    {
        printf("Menu:\n\t1.PUSH\n\t2.POP\n\t0.EXIT\n");
        printf("Enter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            push(stack,&top);
            display(stack,top);
            break;
        case 2:
            if(!isempty(top))             ///check for underflow
            {
                elem=pop(stack,&top);
                printf("The deleted element is %d\n",elem);
            }
            else
                printf("Deletion not possible! ");
            display(stack,top);
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong entry! ");
        }

    }
}
