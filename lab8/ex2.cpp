
/*

Implement Tree ADT using binary character tree with following methods:
1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search

*/

#include <iostream>
using namespace std;

class Tree
{
    public:
        struct Tnode
        {
            char data;
            Tnode * left = nullptr;
            Tnode * right = nullptr;
        };
        Tree()
        {
            root=nullptr;
        }
        ~Tree()
        {
            free_tree(root);
        }
        int insert(char);
        void inorder();
        void preorder();
        void postorder();
        int search(char);
        
    private:
        Tnode* root;
        void inorder_rec(Tnode*);
        void preorder_rec(Tnode*);
        void postorder_rec(Tnode*);
        void free_tree(Tnode*);
};


class Q_sll
{
    private:
        struct node
        {
            Tree::Tnode* data;
            struct node * next;
        }*head,*tail;
        void free_queue();
    public:
        Q_sll()
        {
            head=tail=nullptr;
        }
        ~Q_sll()
        {
            free_queue();
        }
        int enq(Tree::Tnode*);
        Tree::Tnode* deq();
        Tree::Tnode* front();
        int is_empty();
};

int main()
{
    Tree tree;
    int ch,res;
    char node;
    do
    {
        cout << "\tMENU\n1. Insert \n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1:
            {
                cout << "Enter character to insert: ";
                cin >> node;
                if (tree.insert(node))
                {
                    cout << node << " was inserted.\n";
                }
                else cout << "Could not insert element.\n";
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
                cout << "Enter character to search: ";
                cin >> node;
                switch (res=tree.search(node))
                {
                    case 0: 
                    {
                        cout << "Tree is empty.\n";
                        break;
                    }
                    case -1:
                    {
                        cout << node << " not found.\n";
                        break;
                    }
                    default:
                    {
                        cout << node << " found at node number "<< res <<'\n';
                        break;
                    }
                }
                break;
            }
            case 6:
            {
                cout << "Exiting...\n";
                break;
            }
            default:
            {
                cout << "Invalid choice.\n";
                break;
            }
        }
    } while (ch!=6);
    return 0;
}

//Inserts element into tree
//Input:    ch - char- character to be inserted
//returns 0 if memory allocation fails, 1 otherwise 
int Tree::insert(char ch)
{
    Tnode * newnode = new Tnode();
    if (newnode==nullptr) return 0;
    newnode->data=ch;
    if (root==nullptr)
    {
        root=newnode;
        return 1;
    }
    Q_sll q;
    Tnode* temp=root;
    while(true)
    {
        if(temp->left!=nullptr)
        {
            q.enq(temp->left);
        }
        else
        {
            temp->left=newnode;
            break;
        }
        if (temp->right!=nullptr)
        {
            q.enq(temp->right);
        }
        else
        {
            temp->right=newnode;
            break;
        }
        temp=q.deq();
    }
    return 1;
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

//Searches tree for element level order
//Input:    ch - char - element to search
//returns index if found, -1 if not, 0 if tree is empty
int Tree::search(char ch)
{
    if (root==nullptr)
    {
        return 0;
    }
    Q_sll q;
    Tnode* temp=root;
    int num=1;
    q.enq(temp);
    do
    {
        temp=q.deq();
        if (temp->data==ch)
        {
            return num;
        }
        if(temp->left!=nullptr)
        {
            q.enq(temp->left);
        }
        if (temp->right!=nullptr)
        {
            q.enq(temp->right);
        }
        num++;
    }while(q.is_empty()!=1);
    return -1;
}

//Helper function for destructor
//Input:    temp - pointer of root
void Tree::free_tree(Tnode* temp)
{
    if (temp==nullptr) return;
    free_tree(temp->left);
    free_tree(temp->right);
    delete temp;
}

int Q_sll::enq(Tree::Tnode* num)
{
    struct node * newnode= new node();
    if (newnode==nullptr) return 0;
    newnode->data=num;
    newnode->next=nullptr;
    if (!is_empty())
    {
        tail->next=newnode;
    }
    else
    {
        head=newnode;
    }
    tail=newnode;
    return 1;
}

Tree::Tnode* Q_sll::deq()
{
    if (is_empty())
    {
        return nullptr;
    }
    Tree::Tnode* num=head->data;
    struct node * temp =head->next;
    delete head;
    head=temp;
    if (is_empty()) tail=nullptr;
    return num;
}

Tree::Tnode* Q_sll::front()
{
    if (is_empty()) return nullptr;
    return head->data;
}

int Q_sll::is_empty()
{
    if (head==nullptr) return 1;
    return 0;
}

void Q_sll::free_queue()
{
    struct node * temp=head;
    while (is_empty()==0)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
    tail=nullptr;
}