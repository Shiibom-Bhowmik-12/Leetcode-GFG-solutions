// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool isPrime(int n)
       {
           if(n<=1) return false;
           if(n==2 || n==3) return true;
           if(n%2==0 || n%3==0) return false;
           for(int i=5; i*i<=n ;i+=6)
           {
               if(n%(i)==0 || n%(i+2)==0) return false;
           }
           return true;
       }
       
       vector<int> primeDivision(int N){
           vector<int> vec;
          for(int i = 1 ;i<=N; i++)
          {
              if(isPrime(i))
              {
                  int pair = N-i;
                  if(isPrime(pair))
                  {
                      vec.push_back(i);
                      vec.push_back(pair);
                      break;
                  }
              }
          }
          return vec;
       }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends