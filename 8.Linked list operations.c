#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *link;
};
///--------------------------------------------------------
void traverse(struct node *start)
{
    printf("\nCurrent list:-\n");
    while(start!=NULL)
    {
        printf(" ---> %d",start->num);
        start=start->link;
    }
}
///--------------------------------------------------------
struct node*  ins_beg(struct node *start)
{
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->link=NULL;
    nptr->num=22;
    nptr->link=start;
    start=nptr;
    return(start);
}
///--------------------------------------------------------
struct node* ins_end(struct node *end)
{
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->link=NULL;
    nptr->num=55;
    end->link=nptr;
    end=nptr;
    return(end);
}
///--------------------------------------------------------
void ins_aftr_mid(struct node *start)
{
    struct node *nptr,*pos;
    nptr=(struct node*)malloc(sizeof(struct node));
///    rider pointer should first pointed to the start.
    pos=start;
    while(pos->num!=11)
        pos=pos->link;///reaching the position where 11 is stored
/*Insert in 3rd position
    for(i=0;i<6;i++)
    {
        pos=pos->link;
        if(i==3)
            break;
    }

*/
    nptr->link=pos->link;///Hand catches the node adjacent to 10
    pos->link=nptr;///node with 10 holds the new node
    nptr->num=111;

}
///--------------------------------------------------------
void ins_bef_mid(struct node *start)
{
    struct node *nptr,*pre,*pos;
    nptr=(struct node*)malloc(sizeof(struct node));
    pre=start;
    while(pre->num!=11)
    {
        pos=pre;
        pre=pre->link;
    }
    nptr->link=pre;
    pos->link=nptr;
    nptr->num=222;
}
///--------------------------------------------------------
struct node*  del_beg(struct node *start)
{
    struct node*pos;
    pos=start;
    start=start->link;
    free(pos);
    return(start);
}
///--------------------------------------------------------
struct node* del_end(struct node *start,struct node *end)
{
    struct node *pos,*pre;
    pos=start;
    while(pos->link!=NULL)
    {
        pre=pos;
        pos=pos->link;
    }
    pre->link=NULL;
    end=pre;
    free(pos);
    return(end);
}
///--------------------------------------------------------
void del_bef_mid(struct node *start)
{
    struct node *pos,*pre,*prev;
    pos=pre=start;
    while(pos->num!=11)
    {
        prev=pre;
        pre=pos;
        pos=pos->link;
    }
    prev->link=pre->link;
    free(pre);

}
///--------------------------------------------------------
void del_aftr_mid(struct node *start)
{
    struct node *pos,*pre;
    pos=pre=start;
    while(pos->num!=11)
        pos=pos->link;
    pre=pos->link;
    pos->link=pre->link;
    free(pre);
}
///--------------------------------------------------------
void del_particular(struct node *start)
{
    struct node *pre,*pos;
    pos=start;
    while(pos->num!=12)
    {
        pre=pos;
        pos=pos->link;
    }
    pre->link=pos->link;
    free(pos);

}
///--------------------------------------------------------
void main()
{
    struct node *nptr,*start,*end;//pos,pre=rider pointer
    int count;
    start=end=NULL;
//    traverse(start);
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->num=15;
    nptr->link=NULL;
    start=nptr;
    end=nptr;
//    traverse(start);
    for(count=0;count<4;count++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
        nptr->num=count+10;
        nptr->link=NULL;
        end->link=nptr;
        end=nptr;
//        traverse(start);
    }

    traverse(start);

    printf("\n\nInsertion At the begining");
    start=ins_beg(start);
    traverse(start);

    printf("\n\nInsertion At the end");
    end=ins_end(end);
    traverse(start);

    printf("\n\nInsertion After the middle");
    ins_aftr_mid(start);
    traverse(start);

    printf("\n\nInsertion Before the middle");
    ins_bef_mid(start);
    traverse(start);

    printf("\n\nDeletion From the beginning");
    start=del_beg(start);
    traverse(start);

    printf("\n\nDeletion From the end");
    end=del_end(start,end);
    traverse(start);

    printf("\n\nDeletion before the middle");
    del_bef_mid(start);
    traverse(start);

    printf("\n\nDeletion After the middle");
    del_aftr_mid(start);
    traverse(start);

    printf("\n\nDelete particular node 12");
    del_particular(start);
    traverse(start);
}
