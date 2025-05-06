/*

Methods to implement list ADT using circularly linked list
Methods implemented:
1.Insert 
    -beginning
    -end
    -position
2.Delete
    -beginning
    -end
    -position
3.Search
4.Display

*/

#include <stdio.h>
#include <stdlib.h>
#include "cll2.hpp"

//Creates a new node dynamically and assigns its data, next and prev initialized to NULL
//Input:    num - int - data to be inserted
//returns 0 if memory allocation fails, pointer to new node otherwise
struct cll::node * cll::createnode(int num)
{
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    if (newnode!=NULL) 
    {
        newnode->data=num;
        newnode->next=newnode;
    }
    return newnode;
}

//Checks if position value is within given bounds
//Input:    pos - int - position to check
//          beg - int - lower bound
//          end - int - upper bound
//returns 1 if valid, 0 otherwise
int cll::validpos(int pos,int beg,int end)
{
    if (pos>=beg && pos<=end) return 1;
    return 0;
}

//Checks if list is empty
//returns 1 if yes, 0 otherwise
int cll::is_empty()
{
    if (size==0) return 1;
    return 0;
}

//Inserts element in beginning of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int cll::insert_beg(int num)
{
    struct node * newnode=createnode(num);
    if (newnode==NULL) return 0;

    if (head==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->next=head;
    }
    tail->next=newnode;
    head=newnode;
    size++;
    return 1;
}

//Inserts element in the end of list by modifying head and tail after inserting at beginning
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int cll::insert_end(int num)
{
    if (insert_beg(num))
    {
        tail=head;
        head=head->next;
        return 1;
    }    
    return 0;
}

//Inserts element at given position of list
//Input:    num - int - number to be inserted
//          pos - int - position at which to be inserted
//returns 0 if memory allocation fails, -1 for invalid position, 1 for success
int cll::insert_pos(int num,int pos)
{
    if (validpos(pos,0,size)==0) return -1;
    if (pos==0) return insert_beg(num);
    if (pos==size) return insert_end(num);
    
    struct node * newnode=createnode(num);
    if (newnode==NULL) return 0;

    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    size++;
    return 1;
}

//Deletes element in the beginning of list
//returns 0 if list is empty, deleted element if successful
int cll::del_beg()
{
    if (head==NULL) return 0;
    int num=head->data;
    size--;
    if (head==tail)
    {
        free(head);
        head=tail=NULL;
        return num;
    }
    head=head->next;
    free(tail->next);
    tail->next=head;
    return num;
}


//Deletes element in the end of list 
//uses deletion at position
//returns 0 if list is empty, deleted element if successful
int cll::del_end()
{
    return del_pos(size-1);
}

//Deletes element at a position of list
//returns -1 if invalid position, deleted element if successful
int cll::del_pos(int pos)
{
    if (validpos(pos,0,size-1)==0) return -1;
    if (pos==0) return del_beg();
    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next; 
    }
    struct node * temp2=temp->next;
    temp->next=temp2->next;
    int num=temp2->data;
    free(temp2);
    size--;
    if (pos==size) 
    {
        tail=temp;
    }
    if (size==0) 
    {
        head=tail=NULL;
    }
    return num;
}

//Searches list for element linearly
//Input:    num - int - element to search
//returns index if found, -1 otherwise
int cll::search(int num)
{
    if (head==NULL) return -1;
    struct node * temp=head;
    int i=0;
    do
    {
        if (temp->data==num)
        {
            return i;
        }
        temp=temp->next;
        i++;
    }while(temp->next!=head);
    return -1;
}

//Displays list with proper format:
//HEAD -> elt -> elt ... -> HEAD
//displays error message if list is empty
void cll::display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node * temp=head;
    printf("\n HEAD ->");
    while(temp!=tail)
    {
        printf(" %d ->",temp->data);
        temp=temp->next;
    }
    printf(" %d -> HEAD\n",temp->data);
}

//Clears dynamically allocated memory of list by repeatedly calling deletion at beginning
void cll::free_list()
{
    while (size!=0)
    {
        del_beg();
    }
}