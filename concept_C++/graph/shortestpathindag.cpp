#include<bits/stdc++.h>
using namespace std;
class graph
{public:
unordered_map<int,list<pair<int,int>>>adj;
 void addEdge(int u,int v, int weight )
 {
    adj[u].push_back({v,weight});
 }
 void printadj()
 {
    for(auto i: adj)
    {
        cout<<i.first<<"->";
        for(auto j: i.second)
        {
            cout<<j.first<<"-"<<j.second<<", ";
        }
        cout<<endl;
    }
 }
 
  void dfs(int i,unordered_map<int,bool>&visited,stack<int>&s )
  {
     visited[i]=true;
     for(auto it:adj[i])
     {
        if(!visited[it.first])
        {
            dfs(it.first,visited,s);
        }
     }
     s.push(i);
  }

  void calmindist(int source,stack<int>&s,vector<int>&dist)
  {
    dist[source]=0;
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        if(dist[temp]!=INT_MAX)
        {
            for(auto it :adj[temp])
            {
              if(dist[temp]+it.second <dist[it.first] )
              {
                 dist[it.first]=dist[temp]+it.second;
              }
            }
        }
    }
  }

};
int main()
{
    graph G;
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    // G.printadj();
    int n= 6;
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            G.dfs(i,visited,s);
        }
    }
    int source=1;
    vector<int>dist(n,INT_MAX);
    G.calmindist(source,s,dist);
    cout<<"Distances are";
    
    for(int i =0;i<dist.size();i++)
    {
        cout<<i <<"->"<<dist[i]<<endl;
    }
    return 0;
}