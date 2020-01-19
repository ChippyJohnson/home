#include<stdio.h>
void main()
{
    float s1,s2,m,r=0;
    printf("\n\nInput: s1 s2 model: ");
    scanf("%f%f%f",&s1,&s2,&m);
    r=(((s1+s2)*15+m*15)/50)+20;
    printf("internal: %.2f",r);
    main();
}

