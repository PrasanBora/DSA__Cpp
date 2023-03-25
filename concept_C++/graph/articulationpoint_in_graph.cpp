
#include<bits/stdc++.h>
using namespace std;

void dfs( int node,int parent,vector<bool>&vis,vector<int>&disc,
           vector<int>&low,vector<int>&ap,unordered_map<int,list<int>>&adj
           ,int &timer)
           {
             vis[node]=1;
             disc[node]=low[node]=timer++;
             

           }
int main()
{
    int n=5;
    int e=5;
    vector<pair<int,int>>edg;
    edg.push_back({0,3});
    edg.push_back({3,4});
    edg.push_back({0,4});
    edg.push_back({0,1});
    edg.push_back({1,2});

    unordered_map<int,list<int>>adj;
    for(int i=0;i<edg.size();i++)
    {
      int u=edg[i][0];
      int v=edg[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);

    }
    int timer=0;
    vector<bool>vis(n,0);
    vector<int>disc(n,-1);
    vector<int>low(n,-1);
    vector<int>ap(n,0);

for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,disc,low,ap,adj,timer);
        }
    }
 cout<<endl<<"Articulation List "<<endl;
for(int i=0;i<n;i++)
    {
      cout<<ap[i]<<"  ";
    }
    cout<<endl;

    return 0;
}