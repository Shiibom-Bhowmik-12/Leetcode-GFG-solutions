// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
   vector<int> vec;
      for(int i=1; i<N-1; i++)
      {
          if((A[i-1]+A[i])>A[i+1]&&(A[i+1]+A[i])>A[i-1]&& (A[i-1]+A[i+1])>A[i] )
          {
              vec.push_back(1);
          }
          else
          {
              vec.push_back(0);
          }
      }
      return vec;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends