// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int N, int arr[]){
        // code here
      int ans=1,k=N-1;
       while(arr[k]!=-1)
       {
           ans++;
           k=arr[k];
       }
       return ans;
    }
};

// Approach: Iterate array from beginning to end, 
// calculate height taking current node as the end 
// (or depth of current node to be accurate) and 
// simply return the max of those values since max 
// depth and height of a tree are same.


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends