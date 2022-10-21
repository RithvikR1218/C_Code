#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * head = NULL;
void push(int x)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void pop()
{
    struct node * temp;
    if (head == NULL)
    {
        printf("Linked List is Empty");
    }
    else 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void top()
{
  printf("%d",head->data);
}

void main (void)
{
    push(5);
    push(3);
    push(1);
    pop();
    pop();
    top();
}
