/*

CODEFORCES QUESTION:
Find number of players left in a game after eliminating i-th person repeatedly

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test,num,min,s1,s2;
    cin >> test;
    vector<vector<int>> res;
    while (test!=0)
    {
        cin >> s1 >> s2;
        for (int i=0;i<s1;i++)
        {
            cin >> num;
            if (i==0) min=num;
            else if (num<min) min=num;
        }
        min--;
        vector <int> arr;
        for (int i=0;i<s2;i++)
        {
            cin >> num;
            arr.push_back(num<min?num:min);
        }
        res.push_back(arr);
        test--;
    }
    cout << "\n";
    for (auto i : res)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}