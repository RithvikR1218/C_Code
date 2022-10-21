#include<stdio.h>

char c[10];
int size = 10;
int r = -1;

int isEmpty()
{
    if (r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if ( r == size - 1 )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

char top()
{
    if (isEmpty(c,r))
    {
        return 0;
    }
    else
    {
        return c[r];
    }
}

void push(char x)
{
    if(isFull(c,r))
    {
        printf("Stack is Full\n");
    }
    else
    {
        r = r + 1;
        c[r] = x;
    }
}

void pop()
{
    if(isEmpty(c,r))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        r = r - 1;
    }
}

void main(void)
{
    int x;
    printf("Enter Length of Expression: \n");
    scanf("%d",&x);
    char a[x];
    printf("Enter an Expression: \n");
    scanf("%s",a);
    int flag = 0;
    for (int i = 0 ; i < x ; i++)
    {
        if ( a[i] == '(' || a[i] == '[' || a[i] == '{' )
        {
            push(a[i]);
            printf("Test1\n");
        }
        else if ( a[i] == ')' || a[i] == ']' || a[i] == '}' )
        {
            if ( a[i] == ')' && top() == '(' )
            {
                pop();
            }
            else if ( a[i] == '}' && top() == '{' )
            {
                pop();
            }
            else if ( a[i] == ']' && top() == '[' )
            {
                pop();
            }
            else 
            {
                flag = 1;
            }
        }
    }   
    if ( flag == 0)
    {
        printf("Statement is Balanced\n");
    }
    else if ( flag == 1)
    {
        printf("Statement is not Balanced\n");
    }
}