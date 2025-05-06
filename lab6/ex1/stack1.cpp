/*

Menu driven program to implement stack ADT using character array of size 5 with the following options:
1. Push
2. Pop
3. Peek
4. Exit

*/
#include <limits>
#include <iostream>
using namespace std;

#define SIZE 5

class stack
{
    private:
        int len;
        char arr[SIZE];
    public:
        stack()
        {
            len=0;
        }
        int push(char);
        char pop();
        char peek();
};

char take_input();
void disp_input(int);
void disp_pop(char);
void disp_peek(char);
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
        cout<<"Stack is full.\n";
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
int stack::push(char elt)
{
    if (len==SIZE)
    {
        return 0;
    }
    arr[len]=elt;
    len++;
    return 1;
}

//Deletes and returns last element of stack, 0 if empty
char stack::pop()
{
    if (len==0)
    {
        return 0;
    }
    char elt=arr[len-1];
    len--;
    return elt;
}

//Returns last element of stack, 0 if empty
char stack::peek()
{
    if (len==0) return 0;
    return arr[len-1];
}