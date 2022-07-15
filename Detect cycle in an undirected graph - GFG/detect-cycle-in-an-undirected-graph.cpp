// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool lol(int i,int V,vector<int>&vis,vector<int> adj[])
    {
        
        queue<pair<int,int>>q;
        // vis[i]=true;
        q.push(make_pair(i,-1));
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int prev=q.front().second;
            vis[i]=1;
            q.pop();
            
            for(auto j:adj[curr])
            {
                if(!vis[j])
                {
                    vis[j]=1;
                    q.push(make_pair(j,curr));
                }
                else if( vis[j]==1 && prev!=j)
                {
                    return true; 
                }
            }
            
        }
        
        return false;
        
    }    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // queue<pair<int,int>>q;
        vector<int>vis(V,0);
        for(int i=0 ; i<V ; i++)
        {
            if(vis[i]==0)
            {
                if(lol(i,V,vis,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // bool check(int i, vector<int> &visited , vector<int> adj[]){
    //     queue<pair<int,int>> q;
    //     visited[i] = 1;
    //     q.push({1,-1});
        
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;
            
    //         for(auto it: adj[node]){
    //             if(visited[it] == 0 ){
    //                 visited[it] = 1;
    //                 q.push({it,node});
    //             }
    //             else if(it!=parent){
    //                 return true ;
    //             }
    //         }
            
    //         return false;
    //     }
        
    // }
    
    // bool isCycle(int V, vector<int> adj[]) {
    //     vector<int> visited(V,0);
        
    //     for(int i = 0 ; i < V ; i++){
    //         if(!visited[i]){
    //             if(check(i,visited,adj)){
    //                 return true;
    //             }
    //         }
    //     }
        
    //     return false;
    // }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends