// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // void BFS(vector<int> adj[],int source,vector<bool> &visited,vector<int> &res){
    //     queue<int> q;
    //     q.push(source);
    //     visited[source]=true;
        
    //     while(!q.empty()){
    //         int curr=q.front();
    //         q.pop();
            
    //         res.emplace_back(curr);
            
    //         for(auto x:adj[curr]){
    //             if(visited[x]==false){
    //                 visited[x]=true;
    //                 q.push(x);
    //             }
    //         }
    //     }
    // }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V+1,false);
        vector<int> res;
        
        // for(int i=0;i<V;i++){
        //     visited[i]=false;
        // }
        
        // for(int i=0;i<V;i++){
        //     if(visited[i]==false){
        //         BFS(adj,i,visited,res);
        //     }
        // }
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            res.emplace_back(curr);
            
            for(auto x:adj[curr]){
                if(visited[x]==false){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends