#include<stdio.h>
struct node
{
    int num;
    struct node *link;
};
void push(struct node **tp)
{
    int elem;
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));///create new node
    printf("enter the element: ");
    scanf("%d",&(nptr->num));///input value
 //   nptr->num=elem;
    nptr->link=*(tp);     ///connecting link
    *(tp)=nptr;            ///top pointing to new node

}
void pop(struct node **tp)
{
    if(*(tp)!=NULL)
    {
        struct node *pos;
        pos=*tp;        ///find position of top
        *(tp)=pos->link;///modify connection
        free(pos);      ///free pos
    }
    else
        printf("CAN'T POP, STACK UNDERFLOW!");
}
void traverse(struct node *top)
{
    if(top==NULL)
        printf("EMPTY LIST");
    else
    {
        printf("\nThe list is:-\n");
        while(top!=NULL)
        {
            printf("%20d\n",top->num);
            top=top->link;
        }
    }
}
void main()
{
    struct node *top;
    top=NULL;
    int opt;

    while(1)
    {
        printf("\nMenu:\n\t1.PUSH\n\t2.POP\n\t0.Exit\n");
        printf("Enter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                push(&top);
                traverse(top);
                break;
            case 2:
                pop(&top);
                traverse(top);
                break;
            case 0:
                exit(0);
                break;
             default:
                printf("Wrong entry");
        }


    }
}
