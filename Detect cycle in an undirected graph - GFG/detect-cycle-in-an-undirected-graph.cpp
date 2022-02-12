// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
bool check(int s, int v, vector<int> adj[], vector<int>& vis){
        queue<pair<int,int>> q;
        vis[s] = true;
        q.push({s,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it, node});
                }
                else if(par != it){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> vis(v+1, 0);
        for(int i = 1; i < v; i++){
            if(!vis[i]){
                if(check(i, v, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
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