// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int pred(char ch){
        if(ch=='^'){
            return 2;
        }
        else if(ch=='*' or ch=='/' or ch=='%'){
            return 1;
        }
        else if(ch=='+' or ch=='-'){
            return 0;
        }
        
        return -1;//for braces
    }
    
    string infixToPostfix(string s)
    {
        // Your code here
        stack<char> st;
        string res="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z'){
                res+=s[i];
            }
            else if(s[i]==')'){
                while(!st.empty() and st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                
                st.pop();
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                while(!st.empty() and pred(st.top())>=pred(s[i])){
                    res+=st.top();
                    st.pop();
                }
                
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        return res;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends