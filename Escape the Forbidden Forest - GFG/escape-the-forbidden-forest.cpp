// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int bridge_util(string & str1, string & str2, int i1, int j1, vector<vector<int>>&dp){
        if(i1 >= str1.length() || j1 >= str2.length()){
            return 0;
        }
        if(dp[i1][j1] != -1) return dp[i1][j1];
        if(str1[i1] == str2[j1]){
            return dp[i1][j1] = 1 + bridge_util(str1, str2, i1 + 1, j1 + 1, dp);
        }
        return dp[i1][j1] = max(bridge_util(str1, str2, i1 + 1, j1, dp), bridge_util(str1, str2, i1, j1 + 1, dp));
    }
    
    
    int build_bridges(string str1, string str2)
    {
        // code here
        vector<vector<int>>dp(str1.length(), vector<int>(str2.length(), -1));
        return bridge_util(str1, str2, 0, 0, dp);
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends