/*

code forces q 1:
find minimum number of moves to get sequence with no duplicates

*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int min_moves(int);
void run_test(int,vector<int>*);

int main()
{
    int test;
    vector<int> res;
    cin >> test;
    run_test(test,&res);
    cout << "\n";
    for (auto i : res)
    {
        cout << i << '\n';
    }
    return 0;
}

//runs each test case and stores result
void run_test(int test,vector<int> * res)
{
    int len;
    for (int i=0;i<test;i++)
    {
        cin >> len;
        res->push_back(min_moves(len));
    }
}

//finds minimum number of moves
int min_moves(int len)
{
    int num;
    unordered_set<int> seq;
    int arr[len];
    for (int i=0;i<len;i++)
    {
        cin >> num;
        arr[i]=num;
    }
    for (int i=0;i<len;i++)
    {
        num=arr[len-i-1];
        if (seq.count(num))
        {
            return len-i;
        }
        else
        {
            seq.insert(num);
        }
    }
    return 0;
}