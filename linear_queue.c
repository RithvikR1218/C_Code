#include<stdio.h>

int a[10];
int size = 10;
int f = -1;
int r = -1;

int isEmpty()
{
    if (f == -1 || f > r )
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
    if (r == size - 1)
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
    if(isFull())
    {
        printf("Queue is Full");
    }
    else
    {    
        if (f == -1)
        {
            f = 0;
        }
        r = r + 1;
        a[r] = i;
        printf("%d is added to the top of queue\n",a[r]);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int b = a[f];
        printf("%d is deleted from the queue\n",b);
        f = f + 1;
    }
}

void main (void)
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(6);
    dequeue();
    dequeue();

}