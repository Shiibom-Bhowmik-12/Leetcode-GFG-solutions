// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
   public:
   //Function to find whether a path exists from the source to destination.
   
   bool solve(vector<vector<int>>& grid, int i, int j){
       if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j])
           return 0;
           
       if(grid[i][j] == 2)
           return 1;
           
       grid[i][j] = 0;
       
       return solve(grid, i+1, j) || solve(grid, i, j+1) || solve(grid, i-1, j) || solve(grid, i, j-1);
   }
   
   
   bool is_Possible(vector<vector<int>>& grid){
       
       for(int i=0;i<grid.size();i++)
           for(int j=0;j<grid[0].size();j++)
               if(grid[i][j] == 1)
                   return solve(grid, i, j);
               
   }
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends