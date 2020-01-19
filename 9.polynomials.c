#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,pwr;
    struct node *link;
};

struct node* atstart(struct node *start,struct node *end,int arr[],int n)
{
    struct node *nptr;
    start=end=NULL;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->coef=arr[0];
    nptr->pwr=n-1;
    nptr->link=NULL;
    start=nptr;
    end=nptr;
//    traverse(start);
    return(start);
}
struct node* append(struct node *end,int arr[],int c,int n)
{

    struct node *nptr;
    nptr=(struct node*)malloc(sizeof(struct node));
    nptr->link=NULL;
    nptr->coef=arr[c];
    nptr->pwr=n-2;
    end->link=nptr;
    end=nptr;
    if(n==0)
        return(end);
};

void traverse(struct node *start)
{

    while(start!=NULL)
    {
        printf("  %d x^%d",start->coef,start->pwr);
        start=start->link;
    }
}

void main()
{

    struct node *p1s=NULL,*p2s=NULL,*p3s=NULL,*p1e=NULL,*p2e=NULL,*p3e=NULL,*ride;
    int arr1[3]= {23,43,5},arr2[3]= {77,11,9},c,size=3,n=3,sum[3];
    p1s=atstart(p1s,p1e,arr1,n);
    p1e=p1s;
    printf("\n");
    p2s=atstart(p2s,p2e,arr2,n);
    p2e=p2s;
    for(c=1; c<size; c++,n--)
        p1e=append(p1e,arr1,c,n);
    traverse(p1s);
    printf("    +\n");
    for(c=1,n=3; c<size; c++,n--)
        p2e=append(p2e,arr2,c,n);
    traverse(p2s);
    printf("\n_________________________\n");
    for(c=0;c<size;c++)
        sum[c]=arr1[c]+arr2[c];
    p3s=atstart(p3s,p3e,sum,3);
    p3e=p3s;
    for(c=1,n=3; c<size; c++,n--)
        p3e=append(p3e,sum,c,n);
    traverse(p3s);

}
