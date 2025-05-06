/*

Methods to implement sorted list ADT using singly linked list
Methods implemented:
1.Insert (maintain ascending order)
2.Merge (combine 2 lists into 3rd)
3.Display
4.Clear

*/

#include <stdio.h>
#include "sll_2.hpp"

//Creates a new node (sll::node) dynamically and assigns its data
//Input:    num - int - data to be inserted
//returns 0 if memory allocation fails, pointer to new node otherwise
struct sll::node * sll::createnode(int num)
{
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL) return 0;
    newnode->data=num;
    return newnode;
}

//Creates a deep copy of list as an array in reverse order
//Input:    arr - int * - empty array of proper size to be stored in
//modifies arr
void sll::store_rev_arr(int * arr)
{
    struct node * temp=head;
    for(int i=length-1;temp!=NULL;i--)
    {
        arr[i]=temp->data;
        temp=temp->next;
    }
} 

//Inserts element in beginning of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int sll::insert_beg(int num)
{
    struct node * newnode=createnode(num);
    if (newnode==0) return 0;
    newnode->next=head;
    if (head==NULL)
    {
        tail=newnode;
    }
    head=newnode;
    length++;
    return 1;
}

//Inserts element at proper position
//Input:    num - int - element to be inserted
//returns 0 for memory allocation fail, 1 otherwise
int sll::insert_asc(int num)
{
    if (length==0 || (head->data>num))
    {
        return insert_beg(num);
    }
    
    struct node * newnode=createnode(num);
    if (newnode==0) return 0;

    struct node * temp = head;
    while(temp->next!=NULL&&temp->next->data<num)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    length++;
    if(newnode->next==NULL) tail=newnode;
    return 1;
}

//Merges 2 lists into third
//Input:    l1 , l2 - singly linked lists
//returns 0 if memory allocation fails, 1 otherwise
int sll::merge(class sll l1,class sll l2)
{
    free_list();
    int arr1[l1.length];
    int arr2[l2.length];
    l1.store_rev_arr(arr1);
    l2.store_rev_arr(arr2);
    int i=0,j=0,flg=1;
    while(i<l1.length&&j<l2.length && flg!=0)
    {
        if (arr1[i]>arr2[j])
        {
            flg=insert_beg(arr1[i]);
            i++;
        }
        else
        {
            flg=insert_beg(arr2[j]);
            j++;
        }
    }
    while (i<l1.length && flg!=0)
    {
        flg=insert_beg(arr1[i]);
        i++;
    }
    while (j<l2.length && flg!=0)
    {
        flg=insert_beg(arr2[j]);
        j++;
    }
    return flg;
}

//Returns head pointer of list
struct sll::node * sll::gethead()
{
    return head;
}

//Displays list with proper format:
//HEAD -> elt -> elt ... -> NULL
//displays error message if list is empty
void sll::display()
{
    if(head==NULL)
    {
        printf(" List is empty\n");
        return;
    }
    struct node * temp=head;
    printf(" HEAD ->");
    while(temp!=tail)
    {
        printf(" %d ->",temp->data);
        temp=temp->next;
    }
    printf(" %d -> NULL\n",temp->data);
}

//Deletes element in the beginning of list
//returns 0 if list is empty, deleted element if successful
int sll::del_beg()
{
    if (head==NULL) return 0;

    struct node * temp = head;
    head=head->next;
    if (head==NULL)
    {
        tail=NULL;
    }
    int num=temp->data;
    free(temp);
    length--;
    return num;
}

//Clears dynamically allocated memory of list by repeatedly calling deletion at beginning
void sll::free_list()
{
    while (length!=0)
    {
        del_beg();
    }
}