#include<stdio.h>
void printArray(int arr[])
{
    int c;
    printf("\n");
    for(c=0; c<8; c++)
        printf("%4d",arr[c]);
}
void merge(int arr[],int min,int mid,int max)
{
    int temp[8];
    int in,a,b,k;
    a=min;      ///index of 1st array
    b=mid+1;    ///index of 2nd array
    printf("\n\nin the merge(), min= %d, mid= %d, max= %d",min,mid,max);
    for(in=min;a<=mid&&b<=max;in++)///if both the arrays are non empty
    {                               ///in= index of the resultant
        if(arr[a]<=arr[b])          ///
            temp[in]=arr[a++];
        else
            temp[in]=arr[b++];
    }
    if(a>mid)       ///if 1st array becomes empty, append the second array to the resultant
        for(k=b;k<max;k++)
            temp[in++]=arr[k];
    else            ///if there are elements only in the 1st array, append it to the resultant
        for(k=a;k<=mid;k++)
            temp[in++]=arr[k];
    for(in=min;in<=max;in++)        ///copy them temporary array to the original array
        arr[in]=temp[in];
    printArray(arr);
}
void part(int arr[],int min,int max)
{
    if(max-min>1)     ///if array has more than one element,partition till the array has 1 element
    {
        int mid;
        mid=(min+max)/2;
        printf("\n\nin part(), min= %d, mid= %d, max= %d",min,mid,max);
        part(arr,min,mid);  ///sending left half for parting
        part(arr,mid+1,max);  ///sending right half for parting
        merge(arr,min,mid,max);///when sorted arrays are found,then it is sent for merging
    }
}

void main()
{
    int arr[8]={100,51,8,22,6,778,199,20};
    printf("\narr= ");
    printArray(arr);
    part(arr,0,7);
    printf("\nThe sorted array is... ");
    printArray(arr);
}
