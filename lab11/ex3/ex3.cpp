/*

Implement hash ADT - with separate chaining with following methods
1. Insert
2. Delete
3. Search

*/


#include <iostream>
#include "sll.h"
using namespace std;

#define SIZE 17

class Hash_sc
{
    private:
        sll arr[SIZE];
        int hash_fn(int);
        int search_idx(int,int *);
    public:
        ~Hash_sc()
        {
            for (int i = 0; i < SIZE; i++)
                arr[i].free_list();
        }
        bool Insert(int,int);
        int Search(int); 
        bool Delete(int);
};

int main()
{
    Hash_sc h;
    int ch,num,res;
    do
    {
        cout << "\n   MENU\n1. Insert\n2. Delete\n3. Search\n4. Exit\n";
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
                else cout << "Memory allocation failed.\n";
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
                cout << "Exiting...\n";
                break;
            }
            default:
            {
                cout << "Invalid choice.\n";
            }
        }
    }while (ch!=4);
    return 0;
}

// Divisive hash function
// Input:   key - int - to be hashed
// Returns index to map to
int Hash_sc::hash_fn(int num)
{
    int i=num%SIZE;
    return i;
}

// Inserts key value pair into hash table
// Input:   key,val - int,int - key value pair
// Returns  true for success, false for failure
bool Hash_sc::Insert(int num,int val)
{
    int idx=hash_fn(num);
    if (arr[idx].insert_beg(num,val)) return true;
    return false;
}

// Private search function to get index from hash function
// Input:   key - int 
// Returns  index if found, -1 if not
int Hash_sc::search_idx(int num,int* val)
{
    int idx=hash_fn(num);
    return arr[idx].search(num,val);
}

// Searches for key in hashtable
// Input:   key - int - key to search
// Returns  value if found, -1 otherwise
int Hash_sc::Search(int num)
{
    int val=-1;
    search_idx(num,&val);
    return val;
}

// Deletes key-value pair from hash table
// Input:   key - int - key to delete
// Returns  true if deleted, false if not found
bool Hash_sc::Delete(int num)
{
    int val,idx=hash_fn(num);
    int pos=arr[idx].search(num,&val);
    if (pos==-1) return false;
    return arr[idx].del_pos(pos)!=-1;
}