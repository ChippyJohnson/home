#include<stdio.h>
void disp(int a[],int size)
{
    int pos;
    printf("\n");
    for(pos=0; pos<size; pos++)
        printf("%4d",a[pos]);
}
///---------------------------------
void insertion(int arr[])
{
    int pass,p,temp;
    for(pass=1; pass<5; pass++)
    {
        for(p=pass; p>0; p--)
        {
            if(arr[p]<arr[p-1])
            {
                temp=arr[p];
                arr[p]=arr[p-1];
                arr[p-1]=temp;
            }

        }
//        disp(arr,5);
    }
    printf("\n The sorted arry is :\n");
    disp(arr,5);
}

///---------------------------------
void ptrinsert(int *ptr)
{
    int pass,p,temp;
    for(pass=1; pass<7; pass++)
    {
        for(p=pass; p>0; p--)
        {
            if(*(ptr+p)<*(ptr+p-1))
            {
                temp=*(ptr+p);
                *(ptr+p)=*(ptr+p-1);
                *(ptr+p-1)=temp;
            }


        }
//        disp(ptr,7);
    }
    printf("\n The sorted array is :\n");
    disp(ptr,7);
}
///-------------------------------
void main()
{
    int arr[5]= {65,23,41,16,5};
    printf("without pointer\n the Array is \n");
    disp(arr,5);
    insertion(arr);

    int arrp[7]= {65,23,41,2,34,16,5};
    printf("\nusing pointer\n the Array is \n");
    disp(arrp,7);
    ptrinsert(arrp);



}
