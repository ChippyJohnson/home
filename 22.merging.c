#include<stdio.h>
#define size1 5
#define size2 9
void merge(int arr1[],int arr2[],int marr[])
{
    int c=0,p1=0,p2=0;
    while(p1<size1 && p2<size2)
    {
        printArray(marr,c);
        if(arr1[p1]==arr2[p2])
        {
            marr[c]=arr1[p1];
            p1++;
        }
        else if(arr1[p1]<arr2[p2])
        {
            marr[c]=arr1[p1];
            p1++;
        }
        else if(arr1[p1]>arr2[p2])
        {
            marr[c]=arr2[p2];
            p2++;
        }
        c++;
    }
    printArray(marr,c);
    if(p1>=size1 && p2<size2)
    {
        while(p2<size2)
        {
            marr[c++]=arr2[p2];
            p2++;
        }
        printArray(marr,c);

    }
    else if(p2>=size2 && p1<size1)
    {
        while(p1<size1)
        {
            marr[c++]=arr1[p1];
            p1++;
        }
        printArray(marr,c);
    }
//   printArray(marr,c);

}
void printArray(int arr[],int size)
{
    int c;

    for(c=0; c<size; c++)
        printf("%4d",arr[c]);
    printf("\n");
}
void main()
{
    int arr1[size1]= {4,6,9,10,100},arr2[size2]= {1,5,8,22,66,177,188,199,200},marr[size1+size2],c;
    printf("arr1= ");
    printArray(arr1,size1);
    printf("arr2= ");
    printArray(arr2,size2);

    merge(arr1,arr2,marr);
    printf("merged array= ");
    printArray(marr,size1+size2);



}
