/*

Program to solve code forces question of maximum value of first tower

*/


#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>*);
int max_first_elt(vector<int>*);


int main()
{
    vector<int> tower={};
    vector<int> result={};
    int test,size,num;
    cin >> test;
    for (int i=0;i<test;i++)
    {
        tower.clear();
        cin >> size;
        for (int j=0;j<size;j++)
        {
            cin >> num;
            tower.push_back(num);
        }
        result.push_back(max_first_elt(&tower));
    }

    for (int i=0;i<test;i++)
    {
        cout << result.at(i) <<"\n";
    }
    return 0;
}

//Sorts vector in place using bubble sort
//Input:    pointer to vector
void sort(vector<int>* tow)
{
    int temp,n=tow->size();
    int flag=0;
    for (int i=0;i<n;i++)
    {
        flag=0;
        for (int j=0;j<n-i-1;j++)
        {
            if (tow->at(j)>tow->at(j+1))
            {
                temp=tow->at(j);
                tow->at(j)=tow->at(j+1);
                tow->at(j+1)=temp;
                flag=1;
            }
        }
        if (flag==0) return;
    }
}

//Returns max value of first element of vector as per conditions
int max_first_elt(vector<int>* tow)
{
    int num=tow->front(),elt,temp;
    sort(tow);
    for (int i=0;i<tow->size();i++)
    {
        elt=tow->at(i);
        if (elt>num)
        {
            temp=num;
            num=(num+elt)/2;
            if ((elt-temp)%2==1)
            {
                num++;
            }
        }
    }
    return num;
}
