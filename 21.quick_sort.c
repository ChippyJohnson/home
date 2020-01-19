#include<stdio.h>
#define size 6
void quick(int arr[],int left,int right)
{
    int pivot,l,r,temp;
    pivot=arr[left];    ///consider 1st element as pivot element
    l=left;             ///and find its actual position in the sorted array
    r=right;
    while(l<r)
    {
        while(pivot<arr[r]) ///compare it with the right most element
            r--;       ///if it is in the required order,decrement r and do the same
        temp=arr[l];   ///if not in the required order, swap them
        arr[l]=arr[r];
        arr[r]=temp;
//        printArray(arr);
        while(pivot>arr[l])///compare it with the left most element
            l++;        ///if it is in the required order, increment f and do the same
    }
    printArray(arr);
    printf("\n");
    if(right-r>1)   ///if the right side of the pivot element contains more than one elements,
        quick(arr,l+1,right);///then perform quick sort on that section
    if(l-left>1)    ///if the left side of the pivot element contains more than one elements,
        quick(arr,left,r-1);///then perform quick sort on that section
}
void printArray(int arr[])
{
    int c;
    for(c=0; c<size; c++)
        printf("%4d",arr[c]);
    printf("\n");
}
void main()
{
    int arr[size]= {50,45,7,65,8,1},c,left=0,right=size-1;
    printf("the array is:- ");
    printArray(arr);
    quick(arr,left,right);
    printf("The sorted array is:- ");
    printArray(arr);
}
