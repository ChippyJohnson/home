#include<stdio.h>

void disp(int a[],int size)
{
    int pos;
    printf("\n");
    for(pos=0; pos<size; pos++)
        printf("%4d",a[pos]);
}
///---------------------------------
void linear(int a[],int size)
{
    int elem,flag=0,pos;
    printf("\nEnter the element: ");
    scanf("%d",&elem);

    for(pos=0;pos<size;pos++)
    {
        if(a[pos]==elem)
            {
                flag=1;
                break;
            }
    }
    if(flag==1)
        printf("Element found");
    else
        printf("Element not found");

}
///----------------------------------------------
void ptrlinear(int *p,int size)
{
     int elem,flag=0,pos;
    printf("\nEnter the element: ");
    scanf("%d",&elem);

    for(pos=0;pos<size;pos++)
    {
        if(*(p+pos)==elem)
            {
                flag=1;
                break;
            }
    }
    if(flag==1)
        printf("Element found");
    else
        printf("Element not found");
}
///-------------------------------------------
void main()
{
    int a[7]={34,65,2,4,5,67,6},size=7;
    disp(a,size);
    printf("\nWithout pointer");
    linear(a,size);
    printf("\nWith pointer");
    ptrlinear(a,size);


}
