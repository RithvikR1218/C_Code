#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next; 
};

struct Node * head = NULL;

void insert_begin(int x)
{
    struct Node * newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
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

void insert_end(int x)
{
    struct Node * newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL; 
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct Node * temp;
        temp = head;
        while (temp->next != NULL )
        {
             temp = temp->next;
        }
        temp->next = newnode ;
    }
}

void insert_position(int x)
{
    int pos;
    printf("Enter position for insertion: ");
    scanf("%d",&pos);
    struct Node * newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * temp = head ;
    newnode->data = x;
    newnode->next = NULL; 
    int count = 1;
    if( pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while ( temp->next != NULL & count != (pos-1))
        {
        temp = temp->next;
        count++;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        struct Node * temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end()
{
    if( head == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        struct Node * temp;
        temp = head;
        while (temp->next->next != NULL )
        {
             temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_position()
{
    int pos;
    printf("Enter position for Deletion: ");
    scanf("%d",&pos);
    struct Node * temp = head ;
    struct Node * prev = NULL;
    int count = 0;
    if( pos == 1)
    {
        head = head-> next;
        free(temp);
    }
    else
    {
        while ( temp->next != NULL & count != (pos-1))
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if(temp->next == NULL)
        {
            free(temp);
            prev->next = NULL;
        }
        else if ( count == pos -1)
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void printlist()
{
    struct Node * current;
    current = head;
    if ( head = NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        while( current->next != NULL)
        {
            printf("%d\n",current->data);
            current = current-> next;
        }
        printf("%d\n",current->data);
    }
}

void main()
{
    insert_begin(4);
    insert_begin(3);
    insert_begin(2);
    insert_begin(1);
    insert_end(5);
    delete_position();
    printlist();
}