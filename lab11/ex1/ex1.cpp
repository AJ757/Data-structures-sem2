/*

Implement hash ADT - with linear probing with following methods
1. Insert
2. Delete
3. Search
4. Display

*/

#include <iostream>
using namespace std;

#define SIZE 17

class Hash_lp
{
    private:
        struct node
        {
            int key;
            int value;
        };
        node arr[SIZE];
        int len;
        int hash_fn(int);
        int search_idx(int);
    public:
        Hash_lp()
        {
            for (int k=0;k<SIZE;k++) arr[k].key=-1;
            len=0;
        }
        bool Insert(int,int);
        int Search(int); 
        bool Delete(int);   
        void Display();
};


int main()
{
    Hash_lp h;
    int ch,num,res;
    do
    {
        cout << "\n   MENU\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter choice : ";
        cin  >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << "Enter key to insert : ";
                cin >> num;
                if (h.Search(num)!=-1)
                {
                    cout << "Key exists.\n";
                    break;
                }
                cout << "Enter value to insert : ";
                cin >> res;
                if (h.Insert(num,res)) cout << num << " inserted.\n";
                else cout << "Hash table is full.\n";
                break;
            }
            case 2:
            {
                cout << "Enter key to delete : ";
                cin >> num;
                res=h.Delete(num);
                if (res) cout << num << " was deleted.\n";
                else cout << "Key not found.\n";
                break;
            }
            case 3:
            {
                cout << "Enter key to search : ";
                cin >> num;
                res=h.Search(num);
                if (res==-1) cout << "Key not found.\n";
                else cout << "Key: " <<num<<"\t Value: "<< res<<'\n';
                break;
            }
            case 4:
            {
                h.Display();
                break;
            }
            case 5:
            {
                cout << "Exiting...\n";
                break;
            }
            default:
            {
                cout << "Invalid choice.\n";
            }
        }
    }while (ch!=5);
    return 0;
}

// Divisive hash function
// Input:   key - int - to be hashed
// Returns index to map to
int Hash_lp::hash_fn(int key)
{
    int i=key%SIZE;
    return i;
}

// Inserts key value pair into hash table
// Input:   key,val - int,int - key value pair
// Returns  true for success, false for failure
bool Hash_lp::Insert(int key,int val)
{
    if (len==SIZE)
    {
        return false;
    }
    int idx=hash_fn(key);
    int start=idx;
    do
    {
        if (arr[idx].key==-1||arr[idx].key==-2)
        {
            arr[idx].key=key;
            arr[idx].value=val;
            len++;
            return true;
        }
        idx=(idx+1)%SIZE;
    }while(idx!=start);
    return false;
}

// Private search function to get index from hash function
// Input:   key - int 
// Returns  index if found, -1 if not
int Hash_lp::search_idx(int key)
{
    int idx=hash_fn(key);
    int s=0;
    while(s<SIZE)
    {
        if (arr[idx].key==key) return idx;
        if(arr[idx].key==-1) return -1;
        s++;
        idx=(idx+1)%SIZE;
    }
    return -1;
}

// Searches for key in hashtable
// Input:   key - int - key to search
// Returns  value if found, -1 otherwise
int Hash_lp::Search(int key)
{
    int idx=search_idx(key);
    if (idx==-1) return -1;
    return arr[idx].value;
}

// Deletes key-value pair from hash table
// Input:   key - int - key to delete
// Returns  true if deleted, false if not found
bool Hash_lp::Delete(int key)
{
    int idx=search_idx(key);
    if (idx==-1) return false;
    arr[idx].key=-2;
    len--;
    return true;
}

// Displays hash table
void Hash_lp::Display()
{
    if (len==0)
    {
        cout << "Empty hash table\n";
        return;
    }
    for (int i=0;i<SIZE;i++)
    {
        if (arr[i].key!=-1&&arr[i].key!=-2) 
        {
            cout << arr[i].key<<" : "<<arr[i].value<<'\n';
        }
    }
    cout <<'\n';
}