// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
int countOfNodes(vector<int> graph[], int n)
    {
        vector<int> disc( n+1 , -1);
        
        queue<int> q;
        q.push(1);
        int timer = 0;
        while(q.size() ){
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                disc[it] = timer%2;
                for(auto node : graph[it]){
                    if(disc[node] == -1) q.push(node);
                }
            }
            timer++;
        }
        
        int odd = 0 , eve = 0;
        for(int i=1; i<=n ;i++){
            if(disc[i] == 0 ){
                eve++;
            }
            else{
                odd++;
            }
        }
        
        int cnt = 0;
        cnt+= (odd)*(odd - 1) >> 1;
        cnt+= (eve)*(eve - 1) >> 1;
        
        return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends