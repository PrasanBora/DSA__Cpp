//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    // dfs method for undirected graph 
    bool dfs(int node ,int parent,vector<bool>&vis ,vector<int>adj[])
    {
        vis[node]=true;
        for( auto it:adj[node] )
        {
            if( it==parent )
               continue;
              
            if( vis[it] == true )
             return true;
            
            if (dfs( it, node,vis,adj ))
             return true;  
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && dfs(i,-1,vis,adj) )
             return true;
        }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends