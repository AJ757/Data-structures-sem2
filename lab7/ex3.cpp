/*

Implementation of queue ADT using singly linked list with following operations:
1. Enqueue
2. Dequeue
3. Front
4. Exit

*/
#include <iostream>
using namespace std;

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
        void disp_queue();
};


void enqueue(int, Q_sll*);
void dequeue(Q_sll*);
void disp_front(Q_sll*);

int main()
{
    Q_sll q;
    int ch,num;
    do
    {
        cout << "\n\tMENU\n1. Enqueue\n2. Dequeue\n3. Front\n4. Exit\n";
        cout << "Enter choice :";
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << "Enter number: ";
                cin >> num;
                enqueue(num,&q);
                break;
            }
            case 2:
            {
                dequeue(&q);
                break;
            }
            case 3:
            {
                disp_front(&q);
                break;
            }
            case 4:
            {
                cout << "Exiting..\n";
                break;
            }
            default:
            {
                cout << "Invalid input.\n";
            }
        }
    }while (ch!=4);
    return 0;
}

//Enqueues element into queue and gives appropriate response to user
//Input:    num - int - element to insert
//          q - queue to insert into
void enqueue(int num,Q_sll* q)
{
    if (q->enq(num)==0)
    {
        cout << "Memory allocation failed\n";
        return;
    }
    cout << num << " added to queue.\n";
}

//Dequeues element from queue and displays to user
//Input:    q - queue to delete from
void dequeue(Q_sll* q)
{
    if (q->is_empty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Dequeued element is " << q->deq() << "\n";
}

//Displays front element of queue
void disp_front(Q_sll* q)
{
    if (q->is_empty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element is " << q->front() << "\n";
}

//Checks if queue is empty
//Returns int - 1 if empty, 0 otherwise
int Q_sll::is_empty()
{
    if (head==nullptr) return 1;
    return 0;
}

//Enqueues element into queue
//Input:    elt - int - element to enqueue
//Returns int - 1 for success, 0 otherwise
int Q_sll::enq(int num) {
    node* newnode = new node;
    if (!newnode) return 0;
    newnode->data = num;
    newnode->next = nullptr;

    if (tail) {
        tail->next = newnode;
    } else {
        head = newnode;
    }
    tail = newnode;
    return 1;
}


//Dequeues element from queue
//Returns int - deleted element, 0 if empty
int Q_sll::deq()
{
    if (is_empty()) {
        return 0;
    }
    int num = head->data;
    node* temp = head;
    head = head->next;
    delete temp;

    if (!head) {
        tail = nullptr;
    }
    return num;
}

//Returns int- front element of queue, 0 empty
int Q_sll::front()
{
    if (is_empty()) return 0;
    return head->data;
}

//Displays queue - helper function for debugging
void Q_sll::disp_queue()
{
    struct node * temp= head;
    cout << "HEAD -> ";
    while (temp!=nullptr)
    {
        cout << temp->data << " -> ";
        temp=temp->next;
    }
    cout << "NULL\n";
}

//Clears memory of queue - helper function for destructor
void Q_sll::free_queue()
{
    struct node * temp=head;
    while (!is_empty())
    {
        temp=head->next;
        delete head;
        head=temp;
    }
}