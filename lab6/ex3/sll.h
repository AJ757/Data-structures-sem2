/*

Header file to implement sorted list ADT using singly linked list
Methods implemented:
1. Push
2. Pop
3. Peek
4. Is_Empty

*/

class stack
{
    private:
        struct node
        {
            unsigned data;
            struct node * next;
        }*head;
    public:
        stack()
        {
            head=nullptr;
        }
        int push(unsigned);
        unsigned pop();
        int is_empty();
        unsigned peek();
};