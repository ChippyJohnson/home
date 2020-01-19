#include<stdio.h>
void disp(int arr[])
{
    int pos;
    printf("\n");
    for(pos=0; pos<6; pos++)
        printf("%4d",arr[pos]);
}
///---------------------------------------------------------------
void selection(int arr[])
{
    int pos,pass,temp,sp,small;
    for(pass=0; pass<6-1; pass++)
    {
        small=arr[pass];
        sp=pass;

        for(pos=pass; pos<6; pos++)
        {

            if(small>arr[pos])

            {
                small=arr[pos];
                sp=pos;
            }
        }
        if(sp!=pass)
        {
            temp=arr[sp];
            arr[sp]=arr[pass];
            arr[pass]=temp;
        }


//        disp(arr);

    }
    printf("\nThe sorted array is\n");
    disp(arr);
}
///--------------------------------------------------------------------
void ptrselect(int *ptr)
{
    int pos,pass,temp,sp,small;
    for(pass=0; pass<6-1; pass++)
    {
        small=*(ptr+pass);
        sp=pass;

        for(pos=pass; pos<6; pos++)
        {

            if(small>*(ptr+pos))
            {
                small=*(ptr+pos);
                sp=pos;
            }
        }

        if(sp!=pass)
        {
            temp=*(ptr+sp);
            *(ptr+sp)=*(ptr+pass);
            *(ptr+pass)=temp;
        }

//       disp(ptr);

    }
    printf("\nThe sorted array is\n");
    disp(ptr);
}
///------------------------------------------------------
void main()
{
    int pos,pass,arr[6]= {40,6,30,5,20,0},temp,sp,small;
    printf("\nthe array is");
    disp(arr);
    selection(arr);

    printf("\nusing pointer");
    int a[6]= {40,6,30,5,20,0};
    printf("\nthe array is");
    disp(a);
    ptrselect(a);

}

