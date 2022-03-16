// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    bool isop(string ch){
        if(ch=="+" or ch=="-" or ch=="*" or ch=="/" or ch=="%"){
            return true;
        }
        
        return false;
    }
    
    int EVA(vector<string> s){
        stack<int> st;
        int res=0;
        
        for(int i=0;i<s.size();i++){
            if(isop(s[i])){
                int k1=st.top();
                st.pop();
                
                int k2=st.top();
                st.pop();
                
                if(s[i]=="+"){
                    st.push(k2+k1);
                }
                else if(s[i]=="-"){
                    st.push(k2-k1);
                }
                else if(s[i]=="*"){
                    st.push(k2*k1);
                }
                else if(s[i]=="/"){
                    st.push(k2/k1);
                }
            }
            else{
                int p=stoi(s[i]);
                st.push(p);
            }
        }
        
        return st.top();        
    }
    
    int evaluatePostfix(string S)
    {
        // Your code here
        vector<string> v;
        for(int i=0;i<S.size();i++){
            string res="";
            res+=S[i];
            v.push_back(res);
        }
        
        return EVA(v);
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends