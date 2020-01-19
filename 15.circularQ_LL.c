#include<stdio.h>
struct node
{
    int num;
    struct node *link;
};
void display(struct node *start,struct node *end)
{
    printf("\nstart= %u  end= %u\nThe list is:-\n",start,end);
    if(start==NULL)
        printf("EMPTY Queue!!!");
    else
    {
        struct node *pos;
        printf("%6d %u",start->num,start);
        pos=start->link;
        while(pos!=start)
        {
            printf("%6d %u",pos->num,pos);
            pos=pos->link;
        }
    }
}
void insert(struct node **pstart,struct node **pend)
{
    struct node *nptr,*pos;
    nptr=(struct node*)malloc(sizeof(struct node)); ///creation of node
    printf("Input element: ");                      ///insert data
    scanf("%d",&(nptr->num));
    nptr->link=NULL;
    if(*pstart==NULL)                               ///if the list is empty, start=end=new node pointer
    {
        *pstart=*pend=nptr;
        (*pstart)->link=*pstart;
    }
    else
    {
       nptr->link=(*pstart);
       (*pend)->link=nptr;                  ///else add at back and modify connections
       *pend=nptr;
    }
}
int delQ(struct node **pstart,struct node **pend,int *elem)
{
    struct node *pos;
    *elem=(*pstart)->num;
    pos=*pstart;            ///position of element=start
    if(*pstart==*pend)      ///if only single node,start=end=NULL
    {
        *pstart=NULL;
        *pend=NULL;
    }
    else                    ///if more than one element in list
    {
        *pstart=(*pstart)->link;        ///modify connections
        (*pend)->link=*pstart;
    }
    free(pos);      ///free(loc)
}
void main()
{
    int opt,elem;
    struct node *start,*end;
    start=end=NULL;
    while(1)
    {
        printf("\n1.insert\n2.delete\n0.quit");
        printf("\nOption: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            insert(&start,&end);
            display(start,end);
            break;
        case 2:
            if(start==NULL)
                printf("Deletion not possible!");   ///check for underflow
            else
            {
                delQ(&start,&end,&elem);
                printf("The deleted element is %d",elem);
            }
            display(start,end);
            break;
        case 0:
            exit(0);
        }
    }
}
