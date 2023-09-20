#include<bits/stdc++.h>
using namespace std;

class graph
{
public:
map<int,list<int>>grp ;
void insert(int u ,int v,bool directed)
{
  grp[u].push_back(v);
  if(!directed)
  {
    grp[v].push_back(u);
  }
}
void print()
{
    for(auto i :grp)
    {
        cout<<i.first<<"-- ";
        for(auto it :i.second)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
};

int main()
{
    int n;
    cout <<"Enter no. of edges";
    cin>>n;

    graph g;
    for(int i=0;i<n;i++)
    {
        int u ,v;
        cin>>u>>v;
        g.insert(u,v,0);
    }
    g.print();
    return 0;
}
