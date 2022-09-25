#include<bits/stdc++.h>
using namespace std;
// first app.
// O(N)^2
// using for loop to find if element know other element 

int celebrity(vector<vector<int> >& M, int n) 
    {
        int count=0;
        bool row,col;
        // code here 
        for(int i=0;i<n;i++)
        {
            row=true;
            for(int j=0;j<n;j++)
            {
                if(M[i][j]!=0)
                  {row=false;
                  break;}
            }
            col=true;
            for(int j=0;j<n;j++)
            {
                if(M[j][i]!=1 && i!=j )
                  {col=false;
                  break;}
            }   
            if(row && col)
             return i;
        }
        return -1;
    }

 // 2- approch 
 //O(n)
// using stack to find a potential celebrity 

 int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i =0;i<n;i++)
        s.push(i);
        
        while(s.size()>1)
        {
            int a =s.top(); s.pop();
            int b =s.top(); s.pop();
            
            if(M[a][b]==1)
             s.push(b);
             else 
             s.push(a);
        }
        int potential =s.top();
        
        for(int i=0;i<n;i++)
          {
              if(M[potential][i]!=0)
               return -1;
          }
        for(int i=0;i<n;i++)
          {
              if(M[i][potential]!=1 && i!=potential )
               return -1;
          }
          
          return s.top();
    }
int main()
{
    return 0;
}