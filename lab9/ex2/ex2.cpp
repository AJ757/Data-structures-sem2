/*

CODEFORCES QUESTION 2
Find difference in strength of n players from strogest of others

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test,len,max1=-1,max2=-1,num;
    vector<vector<int>> res;
    cin >> test;
    while (test!=0)
    {
        cin >> len;
        int arr[len];
        max1=-1;max2=-1;
        for(int i=0;i<len;i++)
        {
            cin >> num;
            if (num > max1)
            {
                max2=max1;
                max1=num;
            }
            else if (num>max2)
            {
                max2=num;
            }
            arr[i]=num;
        }
        vector<int> arr2;
        for (int i=0;i<len;i++)
        {
            if(arr[i]==max1)
            {
                arr2.push_back(max1-max2);
            }
            else
            {
                arr2.push_back(arr[i]-max1);
            }
        }
        res.push_back(arr2);
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