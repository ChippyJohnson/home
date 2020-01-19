#include<stdio.h>
struct node
{
    int num;
    struct node *Lchild,*Rchild;
};
int isempty(struct node *root)
{
    if(root==NULL)
        return 1;
    return 0;
}
void traverse(struct node *root)
{
    if(root==NULL)
        return;
    traverse(root->Lchild);
    printf("%4d",root->num);
    traverse(root->Rchild);
}
int elementFound(struct node *root,int elem)
{
    if(root==NULL)
        return 0;
    else if(elem==root->num)
        return 1;
    else if(elem<root->num)
        return(elementFound(root->Lchild,elem));
    else
        return(elementFound(root->Rchild,elem));
}
struct node* findParent(struct node *par,int elem)
{
    struct node *loc;
    if(elem==par->num)
        return NULL;
    else if(elem<par->num)
        loc=par->Lchild;
    else
        loc=par->Rchild;
    while(loc!=NULL&&loc->num!=elem)
    {
        par=loc;
        if(elem<loc->num)
            loc=loc->Lchild;
        else
            loc=loc->Rchild;
    }
    return(par);
}
void insert(struct node **root,int elem)
{
    if(!elementFound(*root,elem) || *root==NULL)
    {
        struct node *nptr,*par;
        nptr=(struct node*)malloc(sizeof(struct node));
        nptr->num=elem;
        nptr->Lchild=nptr->Rchild=NULL;
        if(*root==NULL)
            *root=nptr;
        else
        {
            par=findParent(*root,elem);
            if(elem<par->num)
                par->Lchild=nptr;
            else
                par->Rchild=nptr;
        }
    }
    else
        printf("It is an existing element.\n");
}
void connection(struct node *loc,struct node **child)
{
    if(loc->Lchild==NULL && loc->Rchild==NULL)
    {
        *child=NULL;
        free(loc);
    }
    else if(loc->Lchild!=NULL && loc->Rchild==NULL)
    {
        *child=loc->Lchild;
        free(loc);
    }
    else if(loc->Lchild==NULL && loc->Rchild!=NULL)
    {
        *child=loc->Rchild;
        free(loc);
    }
    else
        printf("***Cannot delete node with 2 children.***");
}
void deletion(struct node **root,int elem)
{
    struct node *par,*loc;
    loc=NULL;
    par=findParent(*root,elem);
    if(par==NULL)
    {
        loc=*root;
        connection(loc,root);
    }
    else if(elem<par->num)
    {
        loc=par->Lchild;
        connection(loc,&(par->Lchild));
    }
    else
    {
        loc=par->Rchild;
        connection(loc,&(par->Rchild));
    }
}
void main()
{
    struct node *root;
    root=NULL;
    int opt,elem;
    while(1)
    {
        printf("\nmenu:\n\t1.Insert\n\t2.Delete\n\t3.Search\n\t0.Exit\n\t\tEnter Option: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d",&elem);
            insert(&root,elem);
            printf("The inorder list is:- ");
            traverse(root);
            break;
        case 2:
            printf("Enter the element to be deleted: ");
            scanf("%d",&elem);
            if(elementFound(root,elem))
                deletion(&root,elem);
            else
                printf("***DELETION NOT POSSIBLE***");
            printf("\nThe inorder list is:- ");
            if(root==NULL)
                printf("Empty List");
            else
                traverse(root);
            break;
        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d",&elem);
            if(elementFound(root,elem))
                printf("*****ELEMENT FOUND.*****");
            else
                printf("*****ELEMENT NOT FOUND.*****");
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong Entry...");
            break;
        }
    }
}
