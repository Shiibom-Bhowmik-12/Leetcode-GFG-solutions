// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> barcketNumbers(string S)
	{
	    // Your code goes here
	    stack<pair<char,int>> st;
	    vector<int> res;
	    int c=1;
	    
	    for(int i=0;i<S.size();i++){
	        if(S[i]=='('){
	            res.push_back(c);
	            st.push({S[i],c});
	            c++;
	        }
	        else if(S[i]==')'){
	            res.push_back(st.top().second);
	            st.pop();
	        }
	    }
	    
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
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.barcketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends