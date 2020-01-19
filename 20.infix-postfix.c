#include<stdio.h>
void printStack(char stack[],int top)
{
    int i;
    printf("\nThe stack is...\n");
    if(top==-1)
        printf("\t\tEMPTY");
    else
        for(i=top;i>=0;i--)
            printf("%4c\n",stack[i]);
    printf("\n");
}
void pushStack(char stack[],int *top,char ch)
{
    (*top)++;
    stack[*top]=ch;
}
char pop(char stack[],int *top)
{
    char ch;
    ch=stack[*top];
    (*top)--;
    return ch;

}
int getPreceed(char ch)
{
    if(ch=='*'||ch=='/')
        return 2;
    if(ch=='+'||ch=='-')
        return 1;
}
void delay()
{
    int d,de;
    for(d=1; d<=32000; d++)
        for(de=1; de<=3000; de++);
}

void main()
{
    int top=-1,pos=0,c;
    char stack[10]="",infix[15]="(a+b)*c-d/e",postfix[15]="",ch;
   // printf("enter the infix exp: ");
    //scanf("%s",&infix);
    printStack(stack,top);
    printf("\nInfix is... ");
    for(c=0;infix[c]!='\0';c++)
        printf("%2c",infix[c]);
    printf("\n");
    for(c=0;(ch=infix[c])!='\0';c++)
    {
         printf("ch = %c",ch);                  ///take the 1st character in the infix[]
         if(ch=='a'||ch=='b'||ch=='c'||ch=='d'||ch=='e')///if it is any variable,insert to postfix[]
            postfix[pos++]=ch;
         else if(ch=='(')                        ///if it is an opening bracket
                 pushStack(stack,&top,ch);
         else if(ch==')')                   ///if it is a closing bracket,pop each element in the stack
         {                                       ///and insert to postfix[]
             while(stack[top]!='(')///(until the top of the stack reaches the corresponding opening brace)
                    postfix[pos++]=pop(stack,&top);
             top--;///pop the corresponding opening brace
         }
         else if(ch == '*' || ch == '/' ||ch== '+' || ch == '-')///if it is any operator,
         {
             while(stack[top] == '*' || stack[top] == '/' || stack[top] == '+' ||stack[top] == '-')
             {                                                  ///check if top contains any operator
                 if(getPreceed(stack[top])>=getPreceed(ch))///check for greater precedence
                    postfix[pos++]=pop(stack,&top); ///higher precedence operator is popped to postfix[]
                 else                               ///if equal precedence, operator at top is placed 1st
                    break;
             }
             pushStack(stack,&top,ch);              ///if low precedence, then push it to stack
         }
         printf("\nPOSTFIX= %s",postfix);
         printStack(stack,top);
         delay();
    }
    while(top!=-1)
        postfix[pos++]=pop(stack,&top);
    printf("\nPOSTFIX= %s",postfix);
    printStack(stack,top);
}
