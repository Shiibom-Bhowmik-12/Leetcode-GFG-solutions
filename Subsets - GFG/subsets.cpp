// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(vector<int> A,vector<vector<int>> &v,vector<int> res){
        if(A.size()==0){
            v.emplace_back(res);
            return;
        }
        
        vector<int> k1=res;
        vector<int> k2=res;
        
        k2.emplace_back(A[0]);
        A.erase(A.begin()+0);
        
        solve(A,v,k1);
        solve(A,v,k2);
    }
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> v;
        if(A.size()==0){
            return v;
        }
        
        //sort(A.rbegin(),A.rend());
        
        vector<int> res;
        solve(A,v,res);
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends