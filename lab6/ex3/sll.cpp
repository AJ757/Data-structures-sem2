/*

Methods to implement stack ADT using singly linked list
Methods implemented:
1. Push
2. Pop
3. Peek
4. Is_Empty

*/

#include "sll.h"
#include <stdlib.h>

int stack::push(unsigned c)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        return 0;
    }
    newnode->next=head;
    head=newnode;
    newnode->data=c;
    return 1;
}

unsigned stack::pop()
{
    if (head==NULL)
    {
        return 0;
    }
    unsigned c=head->data;
    struct node * temp=head;
    head=head->next;
    free(temp);
    return c;
}

int stack::is_empty()
{
    if (head==NULL)
    {
        return 1;
    }
    return 0;
}

unsigned stack::peek()
{
    if (head==NULL)
    {
        return 0;
    }
    return head->data;
}