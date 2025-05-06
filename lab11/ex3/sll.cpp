/*

Program to implement list ADT using singly linked list
Methods implemented:
1.Insert 
    -beginning
    -end
2.Delete
    -beginning
    -end
    -position
3.Search
*/

#include "sll.h"

//Creates a new node (sll::node) dynamically and assigns its data
//Input:    num,val - int,int - data to be inserted
//returns 0 if memory allocation fails, pointer to new node otherwise
struct sll::node * sll::createnode(int num,int val)
{
    struct node * newnode =new node;
    if (newnode==nullptr) return 0;
    newnode->key=num;
    newnode->value=val;
    return newnode;
}

//Checks if position value is within given bounds
//Input:    pos - int - position to check
//          beg - int - lower bound
//          end - int - upper bound
//returns 1 if valid, 0 otherwise
int sll::validpos(int pos,int beg,int end)
{
    if (pos>=beg && pos<=end) return 1;
    return 0;
}

//Creates a deep copy of list as an array
//Input:    arr - int * - empty array of proper size to be stored in
//modifies arr
void sll::store_arr(int * arr)
{
    struct node * temp=head;
    for(int i=0;temp!=nullptr;i++)
    {
        arr[i]=temp->key;
        temp=temp->next;
    }
}

//Inserts element in beginning of list
//Input:    num,val - int,int - key value pair to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int sll::insert_beg(int num,int val)
{
    struct node * newnode=createnode(num,val);
    if (newnode==0) return 0;
    newnode->next=head;
    if (head==nullptr)
    {
        tail=newnode;
    }
    head=newnode;
    length++;
    return 1;
}

//Inserts element in the end of list
//Input:    num,val - int,int - key value pair to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int sll::insert_end(int num,int val)
{
    if (head==nullptr)
    {
        return insert_beg(num,val);
    }
    struct node * newnode=createnode(num,val);
    if (newnode==0) return 0;
    newnode->next=nullptr;
    tail->next=newnode;
    tail=newnode;
    length++;
    return 1;
}

//Deletes element in the beginning of list
//returns 0 if list is empty, deleted element if successful
int sll::del_beg()
{
    if (head==nullptr) return 0;

    struct node * temp = head;
    head=head->next;
    if (head==nullptr)
    {
        tail=nullptr;
    }
    int num=temp->key;
    delete temp;
    length--;
    return num;
}

//Deletes element in the end of list 
//uses deletion at position
//returns 0 if list is empty, deleted element if successful
int sll::del_end()
{
    return del_pos(length-1);
}

//Deletes element at a position of list
//returns -1 if invalid position, deleted element if successful
int sll::del_pos(int pos)
{
    if (validpos(pos,0,length-1)==0) return -1;
    if (pos==0) return del_beg();
    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    struct node * temp2=temp->next;
    temp->next=temp2->next;
    int num=temp2->key;
    delete temp2;
    length--;

    if (pos==length) tail=temp;
    if (length==0) head=nullptr;
    return num;
}

//Searches list for element linearly
//Input:    num - int - element to search
//returns index if found, -1 otherwise
int sll::search(int num,int *val)
{
    if (head==nullptr) return -1;
    struct node * temp=head;
    int i=0;
    do
    {
        if (temp->key==num)
        {
            *val=temp->value;
            return i;
        }
        temp=temp->next;
        i++;
    }while(temp!=nullptr);
    *val=-1;
    return -1;
}


//Clears dynamically allocated memory of list by repeatedly calling deletion at beginning
void sll::free_list()
{
    while (length!=0)
    {
        del_beg();
    }
}