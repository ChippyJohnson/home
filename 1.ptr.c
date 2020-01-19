#include<stdio.h>
void main()
{
    int a ,b,c,*ip;

    printf("&a=%u,&b=%u,&c=%u,&ip=%u",&a,&b,&c,&ip);

    printf("\n\na__________________________");
    ip=&a;
    printf("\nInitial value of a: %d",*ip);
    ip=&b;
    printf("\nInitial value of b: %d",*ip);
    ip=&c;
    printf("\nInitial value of c: %d",*ip);

    printf("\n\nb__________________________");
    ip=&a;
    *ip=5;
    ip=&b;
    *ip=10;
    ip=&c;
    *ip=20;
    printf("\nHard coded values of a=%d,b=%d,c=%d",a,b,c);

    printf("\n\nc__________________________");
    ip=&a;
    printf("\nenter value for a:");
    scanf("%d",ip);
    ip=&b;
    printf("\nenter value for b:");
    scanf("%d",ip);
    ip=&c;
    printf("\nenter value for c:");
    scanf("%d",ip);
    printf("\nsoft coded values of a=%d,b=%d,c=%d",a,b,c);

    printf("\n\nd__________________________");
    ip=&a;
    *ip=*ip+10;
    ip=&b;
    *ip=*ip+10;
    ip=&c;
    *ip=*ip+10;
    printf("\nmodified values of a=%d,b=%d,c=%d",a,b,c);

    printf("\n\ne__________________________");
    ip=&a;
    printf("\na=%d",*ip);
    ip--;
    printf("\nb=%d",*ip);
    ip--;
    printf("\nc=%d",*ip);


}

