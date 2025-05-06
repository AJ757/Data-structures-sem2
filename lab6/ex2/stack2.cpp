/*

Menu driven program to implement stack ADT using singly linked list with the following options:
1. Push
2. Pop
3. Peek
4. Exit

*/
#include <limits>
#include <stdlib.h>
#include <iostream>
using namespace std;

class stack
{
    private:
        struct node
        {
            char data;
            struct node * next;
        }*head;
    public:
        stack()
        {
            head=nullptr;
        }
        int push(char);
        char pop();
        char peek();
        void free_list();
};

char take_input();
void disp_input(int);
void disp_peek(char);
void disp_pop(char);
int main()
{
    stack s;
    int ch;
    char elt;
    do
    {
        cout<<"\n\tMENU\n1.Push\n2.Pop\n3.Peek\n4.Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;
        if (cin.fail())
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        switch(ch)
        {
            case 1:
            {
                elt=take_input();
                if (elt!=0) 
                {
                    disp_input(s.push(elt));
                }
                break;
            }
            case 2:
            {
                disp_pop(s.pop());
                break;
            }
            case 3:
            {
                disp_peek(s.peek());
                break;
            }
            case 4:
            {
                cout<<"Exiting ...\n";
                break;
            }
            default:
            {
                cout<<"Invalid input.\n";
            }
        }
    }while(ch!=4);
    s.free_list();
    return 0;
}

//takes input from user and returns it if valid, 0 if not
char take_input()
{
    char elt;
    cout<<"Enter element: ";
    cin>>elt;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a character.\n";
        return 0;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return elt;
}

//Displays input status to user
void disp_input(int num)
{
    if (num==0)
    {
        cout<<"Memory allocation failed.\n";
        return;
    }
    cout<<"Element pushed to stack.\n";
}

//Displays deleted element and error message if empty
void disp_pop(char elt)
{
    if (elt==0)
    {
        cout<<"Stack is empty.\n";
        return;
    }
    cout<<elt<<" was popped.\n";
}

//Displays the last element of stack, error message if empty
void disp_peek(char elt)
{
    if (elt==0)
    {
        cout<<"Stack is empty.\n";
        return;
    }
    cout<<elt<<" is the last element.\n";
}

//Pushes elt element into stack
int stack::push(char c)
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

//Deletes and returns last element of stack, 0 if empty
char stack::pop()
{
    if (head==NULL)
    {
        return 0;
    }
    char c=head->data;
    struct node * temp=head;
    head=head->next;
    free(temp);
    return c;
}

//Returns last element of stack, 0 if empty
char stack::peek()
{
    if (head==NULL)
    {
        return 0;
    }
    return head->data;
}

//Repeatedly deletes last element till stack is empty
void stack::free_list()
{
    while(head!=NULL)
    {
        pop();
    }
}