/*

Header file to implement sorted list ADT using circularly linked list
Methods implemented:
1.Insert 
    -beginning
    -end
    -position
2.Delete
    -beginning
    -end
    -position
3.Search
4.Display

*/

class cll
{
    private:
        struct node
        {
            int data;
            struct node * next;
        }*head,*tail;
        int size;

    public:
        cll()
        {
            head=nullptr;
            tail=nullptr;
            size=0;
        }
        struct node * createnode(int);
        int validpos(int,int,int);
        int is_empty();
        int insert_beg(int);
        int insert_end(int);
        int insert_pos(int,int);
        int del_beg();
        int del_end();
        int del_pos(int);
        int search(int);
        void display();
        void free_list();
};