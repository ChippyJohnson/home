#include<stdio.h>
struct student
{
    int num;
    char name[20],batch;
    float mark;
}a,b,*ptr;
void main()
{
    printf("\na.Address:\n\t&num=%u\n\t&name=%u\n\t&batch=%u\n\t&mark=%u\n\t&a=%u",&a.num,&a.name,&a.batch,&a.mark,&a);
    ptr=&b;
    printf("\nb.address:\n\t&num=%u\n\t&name=%u\n\t&batch=%u\n\t&mark=%u\n\t&ptr=%u\n\t&b=%u",&ptr->num,&ptr->name,&ptr->batch,&ptr->mark,&ptr,&b);

    printf("\n\na__________________");
    printf("\na.Initial values:\n\tnum=%c\n\tname=%s\n\tbatch=%c\n\tmark=%f",a.num,a.name,a.batch,a.mark);
    printf("\nb.Initial values:\n\tnum=%c\n\tname=%s\n\tbatch=%c\n\tmark=%f",ptr->num,ptr->name,ptr->batch,ptr->mark);

    printf("\n\nb__________________");
    a.num=10;
    strcpy(a.name,"chippy");
    a.batch='A';
    a.mark=70.5;
    ptr->num=20;
    strcpy(ptr->name,"johnson");
    ptr->batch='B';
    ptr->mark=90.5;
    printf("\na.Hard coded:\n\tnum=%d\n\tname=%s\n\tbatch=%c\n\tmark=%f",a.num,a.name,a.batch,a.mark);
    printf("\nb.Hard coded:\n\tnum=%d\n\tname=%s\n\tbatch=%c\n\tmark=%f",ptr->num,ptr->name,ptr->batch,ptr->mark);

    printf("\n\nc__________________");

    printf("\na.enter the values of num,name,batch,mark\n");
    scanf("%d%s %c%f",&a.num,&a.name,&a.batch,&a.mark);
    printf("\nb.enter the values of num,name,batch,mark\n");
    scanf("%d%s %c%f",&ptr->num,&ptr->name,&ptr->batch,&ptr->mark);
    printf("\na.Soft coded:\n\tnum=%d\n\tname=%s\n\tbatch=%c\n\tmark=%f",a.num,a.name,a.batch,a.mark);
    printf("\nb.soft coded:\n\tnum=%d\n\tname=%s\n\tbatch=%c\n\tmark=%f",ptr->num,ptr->name,ptr->batch,ptr->mark);

    printf("\n\nd__________________");
    a.num+=5;
    strcat(a.name,"Sebu");
    a.batch='c';
    a.mark+=100;
    ptr->num+=5;
    strcat(ptr->name,"sebastian");
    ptr->batch='d';
    ptr->mark+=100;
    printf("\na.modified:\n\tnum=%d\n\tname=%s\n\tbatch=%c\n\tmark=%f",a.num,a.name,a.batch,a.mark);
    printf("\nb.modified:\n\tnum=%d\n\tname=%s\n\tbatch=%c\n\tmark=%f",ptr->num,ptr->name,ptr->batch,ptr->mark);
}
