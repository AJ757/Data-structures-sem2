/*

Menu driven program to check if a string of paranthesis is valid.
Implemented using stack

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

string take_input();
int balance(string);
int main()
{
    int ch;
    int res;
    do
    {
        cout<<"\n\tMENU\n1.Balance string\n2.Exit\n";
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
                res=balance(take_input());
                if (res)
                {
                    cout<<"Valid expression\n";
                }
                else
                {
                    cout<<"Invalid expression\n";
                }
                break;
            }
            case 2:
            {
                cout<<"Exiting ...\n";
                break;
            }
            default:
            {
                cout<<"Invalid input.\n";
            }
        }
    }while(ch!=2);
    return 0;
}

//Takes input expression from user and returns as string
string take_input()
{
    string elt;
    cout<<"Enter string: ";
    cin>>elt;
    cin.clear();
    return elt;
}

//Checks if expression is valid , returns 1 if yes, 0 otherwise
int balance(string str)
{
    stack s;
    char elt;
    int len=str.length();
    for (int i=0;i<len;i++)
    {
        elt=str.at(i);
        if (elt=='(')
        {
            s.push('(');
        }
        else if (elt==')')
        {
            if (s.pop()==0)
            {
                return 0;
            }
        }
        else
        {
            s.free_list();
            return 0;
        }
    }
    if (s.pop()==0) return 1;
    s.free_list();
    return 0;
}

//Pushes element into stack
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

//Deletes and returns last element of stack, returns 0 if empty
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

//Returns last element of stack, returns 0 if empty
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