/*
Header file to implement list ADT with sll
*/
class sll
{
    private:
        struct node
        {
            int key;
            int value;
            struct node * next;
        }*head,*tail;
        int length;
    public:
        sll()
        {
            head=nullptr;
            tail=nullptr;
            length=0;
        }
        struct node * createnode(int,int);
        int validpos(int,int,int);
        void store_arr(int *);
        int insert_beg(int,int);
        int insert_end(int,int);
        int del_beg();
        int del_end();
        int del_pos(int);
        int search(int,int*);
        void free_list();
};
