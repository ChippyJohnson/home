#include<stdio.h>
void disp(int a[],int size)
{
    int pos;
    printf("\n");
    for(pos=0; pos<size; pos++)
        printf("%4d",a[pos]);
}
///____________________________________________________________
void bubble(int arr[],int size)
{
    int pass,pos,sc,temp;
    for(pass=0; pass<size-1; pass++)
    {
        sc=0;
        for(pos=0; pos<size-1-pass; pos++)
            if(arr[pos]>arr[pos+1])
            {
                temp=arr[pos];
                arr[pos]=arr[pos+1];
                arr[pos+1]=temp;
                sc++;
            }
        if(sc==0)
            break;
    }
    printf("\nThe sorted array is\n");
    disp(arr,size);
}
///______________________________________________________________
void binary(int a[],int size)
{

    int mid,beg,end,e;
    printf("Enter the element to be searched ");
    scanf("%d",&e);
    beg=0;
    end=size;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==e)
            break;
        else if(e>a[mid])
            beg=mid+1;
        else
            end=mid-1;
    }
    if(beg<=end)
        printf("the element is found in the position %d",mid);
    else
        printf("the element is not found ");

}
///______________________________________________________________________
void ptrbinary(int *p,int size)
{

    int mid,beg,end,e;
    printf("Enter the element to be searched ");
    scanf("%d",&e);
    beg=0;
    end=size;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(*(p+mid)==e)
            break;
        else if(e>*(p+mid))
            beg=mid+1;
        else
            end=mid-1;
    }
    if(beg<=end)
        printf("the element is found in the position %d",mid);
    else
        printf("the element is not found ");

}
///________________________________________________________________________
void main()
{
    int a[7]= {34,65,2,4,5,67,6},size=7;
    printf("The given array:-\n");
    disp(a,size);
    bubble(a,size);
    printf("\nWithout pointer\n");
    binary(a,size);
    printf("\nWith pointer\n");
    ptrbinary(a,size);

}
