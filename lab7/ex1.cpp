/*

Implementation of queue ADT using integer array with following operations:
1. Enqueue
2. Dequeue
3. Front
4. Exit

*/
#include <iostream>
using namespace std;

#define SIZE 5

class Q_array
{
    private:
        int arr[5];
        int rear;
    public:
        Q_array()
        {
            rear=-1;
        }
        void enq(int);
        int deq();
        int front();
        int is_full();
        int is_empty();
};

void enqueue(int, Q_array*);
void dequeue(Q_array*);
void disp_front(Q_array);

int main()
{
    Q_array q;
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
                disp_front(q);
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
void enqueue(int num,Q_array* q)
{
    if (q->is_full())
    {
        cout << "Queue is full.\n";
        return;
    }
    q->enq(num);
}

//Dequeues element from queue and displays to user
//Input:    q - queue to delete from
void dequeue(Q_array* q)
{
    if (q->is_empty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Dequeued element is " << q->deq() << "\n";
}

//Displays front element of queue
void disp_front(Q_array q)
{
    if (q.is_empty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element is " << q.front() << "\n";
}

//Checks if queue is empty
//Returns int - 1 if empty, 0 otherwise
int Q_array::is_empty()
{
    if (rear==-1) return 1;
    return 0;
}

//Checks if queue is full
//Returns int - 1 if full, 0 otherwise
int Q_array::is_full()
{
    
    if (rear==SIZE-1) return 1;
    return 0;
}

//Enqueues element into queue
//Input:    elt - int - element to enqueue
void Q_array::enq(int elt)
{
    if (is_full()) return;
    arr[rear+1]=elt;
    rear++;
}

//Dequeues element from queue
//Returns int - deleted element, 0 if empty
int Q_array::deq()
{
    if (is_empty()) return 0;
    int num=arr[0];
    for (int i=0;i<rear;i++)
    {
        arr[i]=arr[i+1];
    }
    rear--;
    return num;
}

//Returns int- front element of queue, 0 if empty
int Q_array::front()
{
    if (is_empty()) return 0;
    return arr[0];
}