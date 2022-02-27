// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
  int len=S.length();
       int z=-1, o=-1, t=-1;
       int ans=INT_MAX;
       
       for(int i=0; i<len; i++){
           if(S[i]=='0')
               z=i;
           else if(S[i]=='1')
               o=i;
           else
               t=i;
               
           if(z==-1 or o==-1 or t==-1)
               continue;
               
           else{
               int temp=i-min(z, min(o, t));
               ans=min(ans, temp+1);
           }
       }
       if(ans==INT_MAX)
           return -1;
           
       else
           return ans;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends