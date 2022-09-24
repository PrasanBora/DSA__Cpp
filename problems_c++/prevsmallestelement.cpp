#include<bits/stdc++.h>
using namespace std;

vector <int> prevsmaller( vector<int> arr )
{
    vector<int>ans;
    stack<int> s;
    for(int i =0;i<arr.size();i++)
    {
        int temp = arr[i];
        while(!s.empty() && s.top()>=temp)
         s.pop();
        
        if(s.empty())
         ans[i]=-1;
         else 
         ans[i]=arr[i];
         s.push(arr[i]);
    }
    return ans;
}

int main()
{
    return 0;
}