/*

Function definitions for tree ADT (binary expression tree)
1. Construct expression tree
2. Inorder
3. Preorder
4. Postorder

*/


#include "exp_tree.h"

//Constructs expression tree from postfix expression
//Input:    str - string - contains postfix expression
//Returns 1 for success, 0 for invalid expression
int Tree::expression_tree(string str)
{
    free_tree(root);
    stack<Tnode*> stk;
    Tnode * newnode;
    for (char ch:str)
    {
        if (ch==' ') continue;
        newnode = new Tnode();
        newnode->data=ch;
        if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
        {
            stk.push(newnode);
        }
        else
        {
            if (stk.size()>=2)
            {
                newnode->right=stk.top();
                stk.pop();
                newnode->left=stk.top();
                stk.pop();
            }
            else
            {
                clear_stack(stk);
                delete newnode;
                return 0;
            }
            stk.push(newnode);
        }
    }
    if (stk.size()==1)
    {
        root=stk.top();
        return 1;
    }
    clear_stack(stk);
    return 0;
}

//Recursive helper function for Inorder traversal
//Input:    temp - pointer to node to traverse
//Displays tree inorder.
void Tree::inorder_rec(Tnode * temp)
{
    if (temp->left!=nullptr) inorder_rec(temp->left);
    cout << temp->data << ' ';
    if (temp->right!=nullptr) inorder_rec(temp->right);
}

//Recursive helper function for Preorder traversal
//Input:    temp - pointer to node to traverse
//Displays tree preorder.
void Tree::preorder_rec(Tnode * temp)
{
    cout << temp->data << ' ';
    if (temp->left!=nullptr) preorder_rec(temp->left);
    if (temp->right!=nullptr) preorder_rec(temp->right);
}

//Recursive helper function for Postorder traversal
//Input:    temp - pointer to node to traverse
//Displays tree postorder.
void Tree::postorder_rec(Tnode * temp)
{
    if (temp->left!=nullptr) postorder_rec(temp->left);
    if (temp->right!=nullptr) postorder_rec(temp->right);
    cout << temp->data << ' ';
}

//Displays tree inorder using recursive helper function
void Tree::inorder()
{
    if (root==nullptr)
    {
        cout << "Tree is empty. \n";
        return;
    }
    inorder_rec(root);
    cout << '\n';
}

//Displays tree preorder using recursive helper function
void Tree::preorder()
{
    if (root==nullptr)
    {
        cout << "Tree is empty. \n";
        return;
    }
    preorder_rec(root);
    cout << '\n';
}

//Displays tree postorder using recursive helper function
void Tree::postorder()
{
    if (root==nullptr)
    {
        cout << "Tree is empty. \n";
        return;
    }
    postorder_rec(root);
    cout << '\n';
}

//Helper function for destructor
//Input:    temp - pointer of root
void Tree::free_tree(Tnode* temp)
{
    if (temp==nullptr) return;
    free_tree(temp->left);
    free_tree(temp->right);
    delete temp;
    root=nullptr;
}

//Function to clear stack of nodes
//Input:    stk - stack of pointers to tree nodes
void Tree::clear_stack(stack<Tnode*>& stk)
{
    while(!stk.empty())
    {
        free_tree(stk.top());
        stk.pop();
    }
}