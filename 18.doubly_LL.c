#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *Llink,*Rlink;
    int num;
};
void display(struct node *start)
{
    printf("\n the list is... ");
    if(start==NULL)
        printf("EMPTY!");
    else
        while(start!=NULL)
        {
            printf("%5d",start->num);
            start=start->Rlink;
        }
}
void addAtBeg(struct node **start,struct node **end)
{
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));///creation of node
    nptr->Llink=nptr->Rlink=NULL;
    printf("Enter the value: ");    ///input data
    scanf("%d",&nptr->num);
    if(*start==NULL)            ///if list is empty, start=end=new node pointer
        *start=*end=nptr;
    else
    {
        nptr->Rlink=(*start);      ///else modify connections
        (*start)->Llink=nptr;
        (*start)=nptr;
    }
}
void addAtEnd(struct node **start,struct node **end)
{
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));///creation of node
    nptr->Llink=nptr->Rlink=NULL;
    printf("Enter the value: ");        ///input data
    scanf("%d",&nptr->num);
    if(*start==NULL)        ///if list is empty, start=end=new node pointer
        *start=*end=nptr;
    else
    {
        nptr->Llink=*end;           ///else modify connections
        (*end)->Rlink=nptr;
        *end=nptr;
    }
}
struct node* findPos(int elem,struct node *start)
{
    while(start!=NULL)
    {
        if(start->num==elem)
            return(start);
        else
            start=start->Rlink;
    }
    if(start==NULL)
       return(NULL);
};
void addAfter(struct node *start,struct node **end)
{
    int elem;
    printf("Enter the node: ");
    scanf("%d",&elem);
    struct node *pos;
    pos=findPos(elem,start);            ///find position of concerned node (pos)
    if(pos==NULL)
        printf("\nelement not found");///position not available
    else
    {
        printf("the position of the %d is %u\n",elem,pos);
        if(pos==(*end))
            addAtEnd(&start,end);       ///if pos=end, create a node at end
        else
        {
            struct node *nptr;
            nptr=(struct node*)malloc(sizeof(struct node));///else create a node
            nptr->Llink=nptr->Rlink=NULL;
            printf("Enter the value: ");            ///input data
            scanf("%d",&nptr->num);
            nptr->Rlink=pos->Rlink;             ///modify connections
            nptr->Llink=pos;
            pos->Rlink->Llink=nptr;
            pos->Rlink=nptr;
        }
    }
}
void addBefore(struct node **start,struct node *end)
{
    int elem;
    printf("Enter the node: ");
    scanf("%d",&elem);
    struct node *pos;
    pos=findPos(elem,*start);           ///find the position of the concerned node(pos)
    if(pos==NULL)
        printf("\nelement not found");
    else
    {
        printf("the position of the %d is %u\n",elem,pos);
        if(pos==(*start))                   ///if pos=start, create a node and add at begining
            addAtBeg(start,&end);
        else
        {
            struct node *nptr;
            nptr=(struct node*)malloc(sizeof(struct node));   ///else create a node
            nptr->Llink=nptr->Rlink=NULL;
            printf("Enter the value: ");        ///input data
            scanf("%d",&nptr->num);
            nptr->Rlink=pos;                ///modify connections
            nptr->Llink=pos->Llink;
            pos->Llink->Rlink=nptr;
            pos->Llink=nptr;
        }
    }
}
void delAtBeg(struct node **start,struct node **end)
{

    if(*start==NULL)
        printf("DELETION NOT POSSIBLE!!");  ///check for empty list
    else
    {
        struct node *pos;
        pos=*start;             ///position of element to be deleted(pos)=start
        if(*start==*end)        ///if only one element in list, start=end=null
            *start=*end=NULL;
        else
        {
            (*start)=(*start)->Rlink;   ///else modify connections
            (*start)->Llink=NULL;
        }
        free(pos);          ///free(pos)
    }
}
void delAtEnd(struct node **start,struct node **end)
{
    if(*start==NULL)
        printf("DELETION NOT POSSIBLE!");   ///check for empty queue
    else
    {
        struct node *pos;   ///position of element to be deleted(pos)=end
        pos=*end;
        if(*start==*end)        ///if only one element, start=end=null
            *start=*end=NULL;
        else
        {
            *end=(*end)->Llink; ///else modify connections
            (*end)->Rlink=NULL;
        }
        free(pos);      ///free(pos)
    }
}


void delAfter(struct node *start,struct node **end)
{
    int elem;
    printf("Enter the node: ");
    scanf("%d",&elem);
    struct node *pos;
    pos=findPos(elem,start);        ///find the position of the node(pos)
    if(pos==NULL||pos==*end)
        printf("\nelement not found");  ///check availability of element to be deleted
    else
    {
        printf("the position of the %d is %u\n",elem,pos);
        if(pos==(*end)->Llink)      ///if pos=Left-link of end, then delete element at end
            delAtEnd(&start,end);
        else
        {
            struct node *loc;
            loc=pos->Rlink;     ///location of the node to be deleted= Right-link of pos
            pos->Rlink=loc->Rlink;///modify connection
            loc->Rlink->Llink=pos;
            free(loc);  ///free(loc)
        }
    }
}
void delBefore(struct node **start,struct node *end)
{
    int elem;
    printf("Enter the element: ");
    scanf("%d",&elem);
    struct node *pos;
    pos=findPos(elem,*start);   ///find the position of the node(pos)
    if(pos==NULL||pos==*start)  ///check availability of element to be deleted
        printf("\nelement not found.Deletion not possible!");
    else
    {
        printf("the position of the %d is %u\n",elem,pos);
        if(pos==(*start)->Rlink)    ///if pos= right-link of start, then delete elemnt at start
            delAtBeg(start,&end);
        else
        {
            struct node *loc;
            loc=pos->Llink;         ///location of the node to be deleted= left-link of pos
            pos->Llink=loc->Llink;  ///modify connections
            pos->Llink->Rlink=pos;
            free(loc);      ///free(loc)
        }
    }
}
void delElem(struct node **start,struct node **end)
{
    int elem;
    printf("Enter the element: ");
    scanf("%d",&elem);
    struct node *pos;
    pos=findPos(elem,*start);   ///find position of element to be deleted(pos)
    if(pos==NULL)
        printf("\nelement not found");///check the availability of elemnt
    else
    {
        printf("the position of the %d is %u\n",elem,pos);
        if(pos==(*start))       ///if pos=start, then delete element at start
            delAtBeg(start,end);
        else if(pos==(*end))        ///if pos=end, then delete element at end
            delAtEnd(start,end);
        else
        {
            pos->Llink->Rlink=pos->Rlink;   ///else modify conections
            pos->Rlink->Llink=pos->Llink;
            free(pos);              ///free(pos)
        }
    }
}
void main()
{
    int opt;
    struct node *start=NULL,*end=NULL;
    while(1)
    {
        printf("\n1.Add at beg\n2.Add at end\n3.add after a node\n4.add before a node\n5.Del at beg\n6.del at end\n7.del after a node\n8.del before a node\n9.del particular node\n0.EXIT");
        printf("\n\t\tEnter Option: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            addAtBeg(&start,&end);
            display(start);
            break;
        case 2:
            addAtEnd(&start,&end);
            display(start);
            break;
        case 3:
            addAfter(start,&end);
            display(start);
            break;
        case 4:
            addBefore(&start,end);
            display(start);
            break;
        case 5:
            delAtBeg(&start,&end);
            display(start);
            break;
        case 6:
            delAtEnd(&start,&end);
            display(start);
            break;
        case 7:
            delAfter(start,&end);
            display(start);
            break;
        case 8:
            delBefore(&start,end);
            display(start);
            break;
        case 9:
            delElem(&start,&end);
            display(start);
            break;
        case 0:
            exit(0);

        default:
            printf("WRONG ENTRY!");
        }
    }
}

