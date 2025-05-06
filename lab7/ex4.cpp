/*

Modification of string given by user using stack
Stack has the following methods:
1. Push
2. Pop

*/

#include <iostream>
#include <string>
using namespace std;
class stack
{
    private:
        struct node
        {
            char data;
            struct node * next;
        }*head;
        void free_stack();
    public:
        stack()
        {
            head=nullptr;
        }
        ~stack()
        {
            free_stack();
        }
        int push(char);
        char pop();
};

void update_stack(string,stack*);

int main()
{

    stack s;
    string str,reversed;
    cout << "Enter string: ";
    getline(cin,str);
    update_stack(str,&s);
    char ch;
    while(ch=s.pop())
    {
        reversed.push_back(ch);
    }

    if (reversed=="")
    {
        cout << "String is empty.\n";
    }
    else
    {    
        reversed=string(reversed.rbegin(),reversed.rend());
        cout<<reversed<<"\n";
    }
    return 0;
}


//Modifies stack by push and pop by using string
//Input:    str - string - to be modified
//          s - stack to be modified
void update_stack(string str,stack* s)
{
    for (const char ch : str)
    {
        if (ch=='+')
        {
            s->pop();
        }
        else
        {
            s->push(ch);
        }
    }
}

//Inputs element into stack
//Input:    c - char to be pushed
// Returns 1 for succes 0 otherwise
int stack::push(char c)
{
    struct node * newnode=new node();
    if (newnode==nullptr)
    {
        return 0;
    }
    newnode->next=head;
    head=newnode;
    newnode->data=c;
    return 1;
}

//Returns popped element, 0 if empty
char stack::pop()
{
    if (head==nullptr)
    {
        return 0;
    }
    char c=head->data;
    struct node * temp=head;
    head=head->next;
    delete temp;
    return c;
}

//Clears memory of stack - helper fn for destructor
void stack::free_stack()
{
    while(head!=nullptr)
    {
        pop();
    }
}