// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string reverseEqn(string s)
    {
        //code here.
        stack<string> stk;
        string k="",temp="";
    
        for(int i=0;i<s.size();i++){
            if(s[i]=='-' or s[i]=='+' or s[i]=='*' or s[i]=='/'){
                stk.push(k);
                temp=s[i];
                stk.push(temp);
                k="";
            }
            else{
                k+=s[i];
            }
        }
        
        // st.push(k);
        // k="";
        while(!stk.empty()){
            k+=stk.top();
            stk.pop();
        }
        
        return k;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends