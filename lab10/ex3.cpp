/*

Priority queue ADT - heap array implementation
1. Insert
2. Delete
3. Display
4. Search
5. Sort (heap sort)
*/

#include <iostream>
using namespace std;
#define SIZE 31

class Priority_queue
{
    private:
        int arr[SIZE];
        int cur;
        void heapify_Down(int*,int,int);
        void heapify_Up();
    public:
        Priority_queue()
        {
            cur=0;
        }
        int insert(int);
        int Delete(int);
        void Display();
        int Search(int);
        void heapSort();
};

int main()
{

    Priority_queue queue;
    int ch,num,res;
    do
    {
        cout <<"\n\tMENU\
        \n1. Insert\
        \n2. Delete\
        \n3. Display\
        \n4. Search\
        \n5. Heap sort\
        \n6. Exit\n";

        cout<< "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << "Enter number to insert: ";
                cin >> num;
                if (queue.insert(num)==-1) cout << "Queue is full.\n";
                break;
            }
            case 2:
            {
                cout << "Enter position to delete: ";
                cin >> num;
                res=queue.Delete(num);
                if (res==-1) cout << "Invalid position\n";
                else cout << "Deleted element is " << res <<'\n';
                break;
            }
            case 3:
            {
                queue.Display();
                break;
            }
            case 4:
            {
                cout << "Enter number to search: ";
                cin >> num;
                res=queue.Search(num);
                if (res==-1) cout << "Not found.\n";
                else cout << num << " found at position "<< res <<'\n';
                break;
            }
            case 5:
            {
                queue.heapSort();
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

//Displays the sorted queue 
void Priority_queue::heapSort() {
    if (cur<1) 
    {
        cout << "Empty queue.\n";
        return;
    }
    int temp[SIZE];
    int tempsize = cur;
    
    for (int i = 1; i <= cur; i++)
        temp[i] = arr[i];

    for (int i=1;i<=tempsize;i++)
    {
        cout<< Delete(1) << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= tempsize; i++)
        arr[i] = temp[i];
    cur=tempsize;
}

// Implements heapify-up on queue
void Priority_queue::heapify_Up()
{
    int parent=cur/2,node=cur,temp;
    while(parent>0 && arr[parent]<arr[node])
    {
        swap(arr[parent],arr[node]);
        node=parent;
        parent/=2;
    }
}
    
// Implements heapify-down on queue
void Priority_queue::heapify_Down(int * arr,int node,int cur) 
{
    int left, right, largest;
    while (true) {
        largest = node;
        left = 2 * node;
        right = left + 1;

        if (left <= cur && arr[left] > arr[largest])
            largest = left;

        if (right <= cur && arr[right] > arr[largest])
            largest = right;

        if (largest == node)
            break;

        swap(arr[node], arr[largest]);
        node = largest;
    }
}

//Inserts element into queue
//Input:    num - int- number to be inserted
//Returns -1 if exceeded size, 0 for success
int Priority_queue::insert(int num)
{
    if (cur==SIZE-1) return -1;
    cur++;
    arr[cur]=num;
    heapify_Up();
    return 0;
}

// Deletes elements from position
//Input:    node - int - position to delete
//Returns -1 for invalid position, dleted element otherwise
int Priority_queue::Delete(int node)
{
    if (node < 1 || node > cur) return -1;
    int num = arr[node];
    arr[node]=arr[cur];
    cur--;
    heapify_Down(arr,node,cur);
    return num;
}

// Displays the queue
void Priority_queue::Display()
{
    if (cur<1) 
    {
        cout << "Empty queue.\n";
        return;
    }
    for (int i=1;i<=cur;i++)
    {
        cout << arr[i] <<" ";
    }
    cout << "\n";
}

//Searches queue for element
//Input:    elt - int - element to search
//Returns   -1 if not found, position if found
int Priority_queue::Search(int elt)
{
    for (int i=1;i<=cur;i++)
    {
        if (arr[i]==elt) return i;
    }
    return -1;
}