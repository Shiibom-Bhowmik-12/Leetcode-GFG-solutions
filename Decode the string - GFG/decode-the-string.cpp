// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string> strstack;
        stack<int> numstack;
        int currnum=0;
        string currstr="";
        
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                currnum=currnum*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                strstack.push(currstr);
                currstr="";
                
                numstack.push(currnum);
                currnum=0;
            }
            else if(s[i]==']'){
                int k=numstack.top();
                numstack.pop();
                
                string prevstr=strstack.top();
                strstack.pop();
                
                while(k--){
                    prevstr+=currstr;
                }
                currstr=prevstr;
            }
            else{
                currstr+=s[i];
            }
        }
        
        return currstr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends