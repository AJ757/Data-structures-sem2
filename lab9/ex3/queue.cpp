/*

Function definitions of queue ADT
1. Enqueue
2. Dequeue
3. Front
4. Is_empty
*/
#include "queue.h"
int Q_sll::is_empty()
{
    if (head==nullptr) return 1;
    return 0;
}

int Q_sll::enq(int num)
{
    struct node * newnode= new node();
    if (newnode==nullptr) return 0;
    newnode->data=num;
    newnode->next=nullptr;
    if (!is_empty())
    {
        tail->next=newnode;
    }
    else
    {
        head=newnode;
    }
    tail=newnode;
    return 1;
}

int Q_sll::deq()
{
    if (is_empty())
    {
        return 0;
    }
    int num=head->data;
    struct node * temp =head->next;
    delete head;
    head=temp;
    if (is_empty()) tail=nullptr;
    return num;
}

int Q_sll::front()
{
    if (is_empty()) return 0;
    return head->data;
}

void Q_sll::free_queue()
{
    struct node * temp=head;
    while (is_empty()==0)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
}