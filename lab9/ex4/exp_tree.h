
/*

Header file for Binary tree ADT with declaration of following:
1. Construct expression tree
2. Inorder
3. Preorder
4. Postorder

*/

#include <iostream>
#include <stack>
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
        int expression_tree(string);
        void inorder();
        void preorder();
        void postorder();
        
    private:
        Tnode* root;
        void inorder_rec(Tnode*);
        void preorder_rec(Tnode*);
        void postorder_rec(Tnode*);
        void free_tree(Tnode*);
        void clear_stack(stack<Tnode*>&);
};
