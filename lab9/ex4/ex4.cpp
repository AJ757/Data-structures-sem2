
/*

Menu driven code to construct expression tree with following options:
1. Input postfix expression
2. Construct expression tree
3. Inorder
4. Preorder
5. Postorder

*/

#include <iostream>
#include "exp_tree.h"
using namespace std;

void construct_tree(Tree*,string);

int main()
{
    Tree exp_tree;
    int ch;
    string str;
    do
    {
        cout <<"\n\tMENU\
        \n1. Input postfix expression\
        \n2. Construct expression tree\
        \n3. Preorder\
        \n4. Inorder\
        \n5. Postorder\
        \n6. Exit\n";
        cout<< "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << "Enter postfix expression: ";
                cin >> str;
                break;
            }
            case 2:
            {
                construct_tree(&exp_tree,str);
                break;
            }
            case 3:
            {
                exp_tree.preorder();
                break;
            }
            case 4:
            {
                exp_tree.inorder();
                break;
            }
            case 5:
            {
                exp_tree.postorder();
                break;
            }
            case 6:
            {
                cout << "Exiting..\n";
                break;
            }
            default:
            {
                cout << "Invalid choice.\n";
            }
        }
        
    }while(ch!=6);
    return 0;
}

//Constructs expression tree and displays appropriate output to user
void construct_tree(Tree* exp_tree,string str)
{
    if (str.empty())
    {
        cout << "Enter expression first.\n";
        return;
    }
    switch (exp_tree->expression_tree(str))
    {
        case 0:
            cout << "Invalid postfix expression\n";
            break;
        case 1:
            cout << "Expression tree constructed.\n";
            break;
    }
}