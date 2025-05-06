/*

Implement Tree ADT using Binary search tree data structure with following methods:
1. Insert
2. Preorder
3. Inorder
4. Postorder
5. Search

*/

#include <iostream>
#include "queue.h"
using namespace std;

class BST
{
    private:
        struct BSTnode 
        {
            int data;
            BSTnode * left=nullptr;
            BSTnode * right=nullptr;
        }* root;
        void clear(BSTnode *);
        BSTnode * insert_rec(BSTnode *,int);
        void inorder_rec(BSTnode *);
        void preorder_rec(BSTnode *);
        void postorder_rec(BSTnode *);
        bool search_q(int,Q_sll*);
    public:
        BST()
        {
            root=nullptr;
        }
        ~BST()
        {
            clear(root);
        }
        void insert(int);
        void inorder();
        void preorder();
        void postorder();
        void search(int);
};

int main()
{
    BST tree;
    int ch,num;
    do
    {
        cout <<"\n\tMENU\
        \n1. Insert\
        \n2. Preorder\
        \n3. Inorder\
        \n4. Postorder\
        \n5. Search\
        \n6. Exit\n";

        cout<< "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << "Enter number to insert: ";
                cin >> num;
                tree.insert(num);
                break;
            }
            case 2:
            {
                tree.preorder();
                break;
            }
            case 3:
            {
                tree.inorder();
                break;
            }
            case 4:
            {
                tree.postorder();
                break;
            }
            case 5:
            {
                cout << "Enter number to search: ";
                cin >> num;
                tree.search(num);
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

//Reccursive helper function to insert element
BST::BSTnode* BST::insert_rec(BSTnode * temp,int num)
{
    if (temp==nullptr)
    {
        BSTnode * newnode=new BSTnode();
        if (newnode==nullptr) return nullptr;
        newnode->data=num;
        return newnode;
    }
    else if (num<temp->data)
    {
        temp->left=insert_rec(temp->left,num);
    }
    else
    {
        temp->right=insert_rec(temp->right,num);
    }
    return temp;
}

//Recursive helper function for Inorder traversal
//Input:    temp - pointer to node to traverse
//Displays tree inorder.
void BST::inorder_rec(BSTnode * temp)
{
    if (temp->left!=nullptr) inorder_rec(temp->left);
    cout << temp->data << " ";
    if (temp->right!=nullptr) inorder_rec(temp->right);
}

//Recursive helper function for Preorder traversal
//Input:    temp - pointer to node to traverse
//Displays tree preorder.
void BST::preorder_rec(BSTnode * temp)
{
    cout << temp->data << " ";
    if (temp->left!=nullptr) preorder_rec(temp->left);
    if (temp->right!=nullptr) preorder_rec(temp->right);
}

//Recursive helper function for Postorder traversal
//Input:    temp - pointer to node to traverse
//Displays tree postorder.
void BST::postorder_rec(BSTnode * temp)
{
    if (temp->left!=nullptr) postorder_rec(temp->left);
    if (temp->right!=nullptr) postorder_rec(temp->right);
    cout << temp->data << " ";
}


//Inserts element into tree using recursive helper function
//Input:    num - int- number to be inserted
void BST::insert(int num)
{
    root=insert_rec(root,num);
}

//Displays tree inorder using recursive helper function
void BST::inorder()
{
    if (root==nullptr) 
    {
        cout << "Tree is empty.\n";
        return;
    }
    inorder_rec(root);
    cout << "\n";
}

//Displays tree preorder using recursive helper function
void BST::preorder()
{
    if (root==nullptr) 
    {
        cout << "Tree is empty.\n";
        return;
    }
    preorder_rec(root);
    cout << "\n";
}

//Displays tree postorder using recursive helper function
void BST::postorder()
{
    if (root==nullptr) 
    {
        cout << "Tree is empty.\n";
        return;
    }
    postorder_rec(root);
    cout << "\n";
}

//Searches tree for element
//Input:    num - int - element to search
//Displays path to node or error message if not found
void BST::search(int num)
{
    Q_sll q;
    int res=search_q(num,&q);
    if (res)
    {
        cout << "Root ";
        while (!q.is_empty())
        {
            cout << ((q.deq()==1)?"-> Right ":"-> Left ");
        }
        cout << "\n";
        return;
    }
    cout << num << " not found.\n";
}

//Helper function to search tree using queue
//Input:    num - int - element to search
//          q - pointer to queue
//returns true/false is element is found 
//          modifies q containing 1/2 for right/left
bool BST::search_q(int num,Q_sll* q)
{
    BSTnode * temp=root;
    int cur;
    while(temp!=nullptr)
    {
        cur=temp->data;
        if (cur==num) return true;
        else if (cur<num)
        {
            q->enq(1);
            temp=temp->right;
        }
        else
        {
            q->enq(2);
            temp=temp->left;
        }
    }
    return false;
}

//Helper function for destructor
//Input:    temp - pointer of root
void BST::clear(BSTnode * temp)
{
    if (temp==nullptr) return;
    if (temp->left!=nullptr) clear(temp->left);
    if (temp->right!=nullptr) clear(temp->right);
    delete temp;
}