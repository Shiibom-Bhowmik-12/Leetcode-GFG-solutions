// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
       long long count[26] = {0};
       long long n = S.length();
       for(int i=0;i<n;i++)
       {
           count[S[i]-'a']++;
       }
       
       long long duplicates=0;
       for(int i=0;i<26;i++)
       {
           duplicates+=count[i]*(count[i]-1)/2;
       }
       if(duplicates>0)
       {
           return 1+(n*(n-1))/2 - duplicates;
       }
       else
       {
           return (n*(n-1))/2;
       }
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends