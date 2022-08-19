#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
     bool isvalid(int x,int y,int n,vector<vector<int>> &m ,vector<vector<int>> visited)
     {
         if( (x<=n-1 && x>=0) && (y<=n-1 && y>=0) && visited[x][y]!=1 && m[x][y]==1)
         return true;
         else return  false;
     }
     
    void solve(vector<vector<int>> &m ,vector<vector<int>>&visited ,vector<string> &ans
                ,int x ,int y ,int n,string path)
    {
        //base case 
        if(x==n-1 && y==n-1)
         {
             ans.push_back(path);
             return ;
         }
         visited[x][y]=1;
         
         if(isvalid(x+1,y,n,m,visited))  // Downward case 
         {
             path.push_back('D');
             solve(m,visited,ans,x+1,y,n,path);
             path.pop_back();
         }
          if(isvalid(x,y-1,n,m,visited))  // left case 
         {
             path.push_back('L');
             solve(m,visited,ans,x,y-1,n,path);
             path.pop_back();
         }
          if(isvalid(x,y+1,n,m,visited))  // right case 
         {
             path.push_back('R');
             solve(m,visited,ans,x,y+1,n,path);
             path.pop_back();
         }
          if(isvalid(x-1,y,n,m,visited))  // upward case 
         {
             path.push_back('U');
             solve(m,visited,ans,x-1,y,n,path);
             path.pop_back();
         }
         
         visited[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        //visited array
        vector<vector<int>> visited (n,vector<int> (n, 0));
        vector<string>ans;
        string path="";
        
        if(m[0][0]==0)
         return ans;
         
        solve(m,visited,ans,0,0,n,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


int main()
{
    return 0;
}