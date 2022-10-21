#include<stdio.h>

int a[10];
int size = 10;
int f = -1;
int r = -1;

int isFull()
{
    if (( f == 0 && r == size - 1) || (f == r + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if ( f == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int i)
{
    if (isFull())
    {
        printf("Circular Queue is Full");
    }
    else
    {
        if ( f == -1)
        {
            f = 0;
        }
        r = (r+1) % size;
        a[r] = i;
        printf("%d is added to the top of queue\n",a[r]);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue is Empty");
    }
    else
    {
        int b = a[f];
        printf("%d is deleted from the queue",b);
        if ( f == r )
        {
            f = -1;
            r = -1;
        }
        else 
        {
            f = (f+1) % size;
        }
    }
}


