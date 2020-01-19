#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,pow;
    struct node *link;
};
struct node* atstart(struct node *start,int c,int p)
{
    struct node *nptr;
    start=NULL;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->coef=c;
    nptr->pow=p;
    nptr->link=NULL;
    start=nptr;
//    traverse(start);
    return(start);
}
/*void display(struct node *s1,struct node *s2)
{
    if(s1->pow==s2->pow)
        traverse(s1);
    else if(s1->pow>s2->pow)
        traverse(s1);
    else
        printf("   ");
}*/
struct node* append(struct node *end,int c,int p)
{
    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->coef=c;
    nptr->pow=p;
    nptr->link=NULL;
    end->link=nptr;
    end=nptr;
    return(end);
};

void traverse(struct node *start)
{
//    printf("\n");
    while(start!=NULL)
    {
        printf("  %d x^%d",start->coef,start->pow);
        start=start->link;
        if(start!=NULL)
            printf(" +");
    }

    printf("\n");
}

void main()
{

    struct node *p1s=NULL,*p2s=NULL,*Rs=NULL,*p1e=NULL,*p2e=NULL,*Re=NULL,*r1,*r2;
    int coef,pow;
    char ch;
    printf("Enter the details of 1st polynomial:-\ncoef & pow: ");
    scanf("%d%d",&coef,&pow);
    p1s=atstart(p1s,coef,pow);
    p1e=p1s;
    /*
        while(pow!=0)
        {
            printf("coef & pow: ");
            scanf("%d%d",&coef,&pow);
            p1e=append(p1e,coef,pow);
        }
        printf("Enter the details of 2nd polynomial:-\ncoef & pow:");
        scanf("%d%d",&coef,&pow);
        p2s=atstart(p2s,coef,pow);
        p2e=p2s;
        while(pow!=0)
        {
            printf("coef & pow: ");
            scanf("%d%d",&coef,&pow);
            p2e=append(p2e,coef,pow);
        }
    */

    printf("append?(y/n) ");
    fflush(stdin);
    scanf("%c",&ch);
    while(ch=='y'||ch=='Y')
    {
        printf("coef & pow: ");
        scanf("%d%d",&coef,&pow);
        p1e=append(p1e,coef,pow);
        printf("append?(y/n) ");
        fflush(stdin);
        scanf("%c",&ch);
//       system("cls");
    }
    printf("Enter the details of 2nd polynomial:-\ncoef & pow:");
    scanf("%d%d",&coef,&pow);
    p2s=atstart(p2s,coef,pow);
    p2e=p2s;
    printf("append?(y/n) ");
    fflush(stdin);
    scanf("%c",&ch);
//    system("cls");
    while(ch=='y'||ch=='Y')
    {
        printf("coef & pow: ");
        scanf("%d%d",&coef,&pow);
        p2e=append(p2e,coef,pow);
        printf("append?(y/n) ");
        fflush(stdin);
        scanf("%c",&ch);
//        system("cls");
    }

///creation of 1st node of the result
    r1=p1s;
    r2=p2s;
    if(r1->pow==r2->pow)
    {
        Rs=atstart(Rs,r1->coef+r2->coef,r1->pow);
        r1=r1->link;
        r2=r2->link;
    }
    else if(r1->pow>r2->pow)
    {
        Rs=atstart(Rs,r1->coef,r1->pow);
        r1=r1->link;
    }
    else
    {
        Rs=atstart(Rs,r2->coef,r2->pow);
        r2=r2->link;
    }
    Re=Rs;
    while(r1!=NULL&&r2!=NULL)
    {
        if(r1->pow==r2->pow)
        {
            Re=append(Re,r1->coef+r2->coef,r1->pow);
            r1=r1->link;
            r2=r2->link;
        }
        else if(r1->pow>r2->pow)
        {
            Re=append(Re,r1->coef,r1->pow);
            r1=r1->link;
        }
        else
        {
            Re=append(Re,r2->coef,r2->pow);
            r2=r2->link;
        }
    }
    while(r1!=NULL)
    {
            Re=append(Re,r1->coef,r1->pow);
            r1=r1->link;
    }
    while(r2!=NULL)
    {
            Re=append(Re,r2->coef,r2->pow);
            r2=r2->link;
    }
    //r1=p1s;
    //r2=p2s;
    traverse(p1s);
    traverse(p2s);
    //display(r1,r2);
    printf("________________________________\n\n");
    traverse(Rs);



}

