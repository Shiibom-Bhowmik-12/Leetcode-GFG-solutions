// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(int one,int zero,int n,string op,vector<string> &res){
        if(n==0){
            res.emplace_back(op);
            return;
        }
        
        string op1=op;
        op1.push_back('1');
        solve(one+1,zero,n-1,op1,res);
        
        if(one>zero){
            string op2=op;
            op2.push_back('0');
            solve(one,zero+1,n-1,op2,res);
        }
        return;
    }
    
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> res;
	    
	    solve(0,0,N,"",res);
	    return res;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends