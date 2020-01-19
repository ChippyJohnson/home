#include<stdio.h>
void printStack(int stack[],int top)
{
    int i;
    if(top==-1)
        printf("EMPTY");
    else
        for(i=top; i>=0; i--)
            printf("%10d\n",stack[i]);
    printf("\n");
}
void pushStack(int stack[],int *top,int ch)
{
    (*top)++;
    stack[*top]=ch;
}
int pop(int stack[],int *top)
{
    int dig;
    dig=stack[*top];
    (*top)--;
    return dig;

}
void evaluate(int stack[],int *top,char ch)
{
    int num1,num2;
    num1=pop(stack,top);
    num2=pop(stack,top);
    switch(ch)
    {
    case '+':
        pushStack(stack,top,num1+num2);
        break;
    case '-':
        pushStack(stack,top,num2-num1);
        break;
    case '*':
        pushStack(stack,top,num1*num2);
        break;
    case '/':
        pushStack(stack,top,num2/num1);
        break;
    default:
        printf("INVALID OPERATION");
        break;
    }
}
void main()
{
    int pos,top=-1,stack[5],c;
    char postfix[30],ch;
    printf("input the postfix expression: ");
    scanf("%s",&postfix);
    for(c=0; (ch=postfix[c])!='\0'; c++)
    {
        if(isdigit(ch))
        {
            ch=(int)(ch-48);
            pushStack(stack,&top,ch);
        }
        else
        {
            if(top==-1||top==0)
            {
                top=-1;
                break;
            }
            evaluate(stack,&top,ch);
        }
        printf("Stack is:-\n");
        printStack(stack,top);
    }
    if(top==0)
    {
        printf("Result =");
        printStack(stack,top);
    }
    else
        printf("INVALID POSTFIX EXPRESSION");
}
