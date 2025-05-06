/*

Header file to implement sorted list ADT using singly linked list
Methods implemented:
1.Insert (maintain ascending order)
2.Merge (combine 2 lists into 3rd)
3.Display
4.Clear

*/

#include <stdlib.h>
class sll
{
    private:
        struct node
        {
            int data;
            struct node * next;
        }*head,*tail;
        int length;
        struct node * gethead();
        struct node * createnode(int);
        int insert_beg(int);
        void store_rev_arr(int *);
        int del_beg();
    public:
        sll()
        {
            head=NULL;
            tail=NULL;
            length=0;
        }
        int insert_asc(int);
        int merge(class sll,class sll);
        void display();
        void free_list();
};