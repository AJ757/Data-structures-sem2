/*

Header file for queue ADT with declaration of following:
1. Enqueue
2. Dequeue
3. Front
4. Is_empty

*/
class Q_sll
{
    private:
        struct node
        {
            int data;
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
        int enq(int);
        int deq();
        int front();
        int is_empty();
};