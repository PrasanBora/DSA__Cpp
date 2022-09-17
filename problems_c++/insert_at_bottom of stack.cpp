#include<bits/stdc++.h>
using namespace std;

void helper(stack<int>&stk,int val)
{
    if(stk.empty())
    {
        stk.push(val);
        return;
    }
    int num = stk.top();
    stk.pop();
    helper(stk,val);
    stk.push(num);
}
int main()
{
    stack<int>s ;
      s.push(1);
      s.push(2);
    helper(s,9);
    return 0;
}