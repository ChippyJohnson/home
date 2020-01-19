#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *link;
};
void display(struct node *start)
{
    printf("\nThe list is:-\n");
    while(start!=NULL)
    {
        printf("%6d %u",start->num,start);
        start=start->link;
    }
}
void addBefore(int n,struct node **pstart)
{
    struct node *pos,*nptr;
    pos=*pstart;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->num=111;
    nptr->link=NULL;
    if(pos->num==n)
    {
        nptr->link=*pstart;
        *pstart=nptr;
    }
    else
    {
        while(pos->link->num!=n)
        {
            pos=pos->link;
        }

        if(pos->link!=NULL)
        {
            nptr->link=pos->link;
            pos->link=nptr;

        }
        else
            printf("\nNode not found");
    }
}
void main()
{
    int c,n;
    struct node *nptr,*start,*end,*pos;
    start=end=NULL;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->num=10;
    nptr->link=NULL;
    start=nptr;
    end=nptr;
//    display(start);
    pos=start;
    for(c=0;c<3;c++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
        nptr->num=(pos->num)+10;
        nptr->link=NULL;
        pos->link=nptr;
        pos=pos->link;
        end=nptr;
    }
    display(start);
    printf("\nSelect a node: ");
    scanf("%d",&n);
    addBefore(n,&start);
    display(start);

}
