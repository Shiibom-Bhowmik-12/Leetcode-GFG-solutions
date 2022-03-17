// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string S) {
        // code here
       stack<int> s;
       s.push(-1);
       int res=0;
       for(int i=0;i<S.length();i++){
           
           if(S[i]=='(') s.push(i);
           else{
               s.pop();
               if(!s.empty()){
                    res=max(res , i-s.top());
               }
               else 
                    s.push(i);
           }
       }
       return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends