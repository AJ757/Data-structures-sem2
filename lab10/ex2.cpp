/*

code forces q 2:
find scores of players for words entered if it matches with words of all, one or none of other players

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> points(int);
vector<vector<int>> run_test(int);

int main()
{
    int test;
    
    cin >> test;
    vector<vector<int>> res=run_test(test);
    cout << "\n";
    for (vector<int> i : res)
    {
        for (int j : i )
        {
            cout << j << ' ';
        }
        cout << "\n";
    }
    return 0;
}

//runs each test case and returns result of all
vector<vector<int>> run_test(int test)
{
    int len;
    vector<vector<int>> res;
    for (int i=0;i<test;i++)
    {
        cin >> len;
        res.push_back(points(len));
    }
    return res;
}

//take input for 3 players and returns result points
vector<int> points(int len)
{
    string str;
    unordered_map<string,int> pts;
    vector<vector<string>> players;
    for (int i=0;i<3;i++)
    {
        vector<string> v;
        for (int j=0;j<len;j++)
        {
            cin >> str;
            v.push_back(str);
            if (pts.count(str)) pts[str]++;
            else pts[str]=1;
        }
        players.push_back(v);
    }

    int sum;
    vector<int> res;
    for (auto i :players)
    {
        sum=0;
        for (auto j : i)
        {
            if (pts[j]==1) sum+=3;
            else if (pts[j]==2) sum +=1;
        }
        res.push_back(sum);
    }
    return res;
}