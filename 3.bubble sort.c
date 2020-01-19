#include<stdio.h>
void disp(int arr[])
{
    int pos;
    printf("\n");
    for(pos=0; pos<6; pos++)
        printf("%4d",arr[pos]);
}
void bubble(int arr[])
{
    int pass,pos,sc=0,temp,count=0;
    for(pass=0; pass<6-1; pass++)
    {

        for(pos=0; pos<6-1-pass; pos++)
        {

            if(arr[pos]>arr[pos+1])

            {
                temp=arr[pos];
                arr[pos]=arr[pos+1];
                arr[pos+1]=temp;
                sc++;
            }
        }
        count++;
        if(sc==0)
            break;


    }

    printf("\nThe sorted array is\n");
    disp(arr);
    printf("\nThe no of pass is %d",count);
}
void ptrbubble(int *ptr)
{
    int pos,pass,temp,sc;
    for(pass=0; pass<6-1; pass++)
    {
        sc=0;
        for(pos=0; pos<6-1-pass; pos++)
            if(*(ptr+pos)>*(ptr+pos+1))
            {
                temp=*(ptr+pos);
                *(ptr+pos)=*(ptr+pos+1);
                *(ptr+pos+1)=temp;
                sc++;
            }
        if(sc==0)
            break;

//        disp(arr1);

    }
    printf("\nThe sorted array is\n");
    disp(ptr);
}
void main()
{
    int arr[6]= {1,2,3,4,4,10},*ptr;
    printf("Given array\n");
    disp(arr);
    bubble(arr);

    printf("\nusing pointer");
    int arr1[6]= {1,2,3,45,4,0};
    printf("\nthe array is");
    disp(arr1);

    ptrbubble(arr1);
}
