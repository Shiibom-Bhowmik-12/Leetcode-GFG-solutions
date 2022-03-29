// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
int n = matrix.size();
int m = 1e9 + 7;
vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

dp[0][0] = {1, matrix[0][0]};

for (int i = 0; i < n; ++i)
{
	for (int j = 0; j < n; ++j)
	{
		int acc = 0;
		if (j > 0 && matrix[i][j - 1] & 1)
		{
			dp[i][j].first += dp[i][j - 1].first;
			acc = dp[i][j - 1].second;
		}
			
		if (i > 0 && matrix[i - 1][j] & 2)
		{
			dp[i][j].first += dp[i - 1][j].first;
			acc = max(acc, dp[i - 1][j].second);
		}
		
		dp[i][j].first %= m;
		
		if (acc)
			dp[i][j].second = acc + matrix[i][j];
	}
}

return {dp[n - 1][n - 1].first, dp[n - 1][n - 1].second};
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends