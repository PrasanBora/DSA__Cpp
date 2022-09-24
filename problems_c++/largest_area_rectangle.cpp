#include<bits/stdc++.h>
using namespace std;

vector<int>leftmin(vector<int>arr)
{
  vector<int>ans;
  stack<int>s;
  for (int i = 0; i < arr.size(); i++)
  {
    while(!s.empty()&& arr[s.top()]>=arr[i])
        s.pop();
    
    if(s.empty())
     ans.push_back(-1);
     else 
     ans.push_back(s.top());
     s.push(i);
  }
  return ans;
}

vector<int>rightmin(vector<int>arr)
{
   vector<int>ans;
  stack<int>s;
  for (int i = arr.size()-1; i >=0; i--)
  {
    while(!s.empty()&& arr[s.top()]>=arr[i])
        s.pop();
    
    if(s.empty())
     ans.push_back(-1);
     else 
     ans.push_back(s.top());
     s.push(i);
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int maxarea(vector<int>vect)
{
    vector<int>left =  leftmin(vect);
    vector<int>right = rightmin(vect);

      int area=0;
    for(int i=0;i<vect.size();i++)
    {
        int l=vect[i];
        int b;
        if(right[i]==-1)
         b= vect.size() -left[i]-1 ;
         else 
         b= right[i]-left[i]-1;

       area=max(area,l*b);
    }
    return area;
}
int main()
{
    return 0;
}