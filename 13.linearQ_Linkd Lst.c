#include<stdio.h>
struct node
{
    int num;
    struct node *link;
};
void insFirst(struct node **f,struct node **b)
{
    int elem;
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the element: ");
    scanf("%d",&elem);
    nptr->num=elem;    ///input value
    nptr->link=NULL;
    *f=*b=nptr;        ///front and back pointing to 1st node
}
void traverse(struct node *f)
{
    if(f==NULL)
        printf("EMPTY LIST");
    else
    {
        printf("\nThe list is:-\n\t");
        while(f!=NULL)
        {
            printf("%5d",f->num);
            f=f->link;
        }
    }
}
void append(struct node **f,struct node **b)
{
    int elem;
    struct node *nptr,*pos;
    pos=*b;
    nptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the element: ");
    scanf("%d",&elem);
    nptr->num=elem;    ///input value
    nptr->link=NULL;

    pos->link=nptr;
    *b=nptr;
}
void del(struct node **f)
{
    if(*f!=NULL)
    {
        struct node *pos;
        pos=*f;
        *f=pos->link;
        free(pos);
        traverse(*f);
    }
    else
        printf("CAN'T DELETE, QUEUE IS EMPTY!");

}
void main()
{
    struct node *f,*b;
    f=b=NULL;
    int opt;
    while(1)
    {
        printf("\nMenu:\n\t1.INSERT\n\t2.DELETE\n\t3.EXIT\n");
        printf("Enter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                if(f==NULL)
                    insFirst(&f,&b);
                else
                    append(&f,&b);
                traverse(f);
                break;
            case 2:
                del(&f);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Wrong entry");
        }
    }


}
