// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s;
        long long maxi=0;
        
        for(long long i=0;i<n;i++){
            while(s.empty()==false and arr[s.top()]>=arr[i]){
                long long ind=s.top();
                s.pop();
                long long res=arr[ind]*(s.empty()?i:i-s.top()-1);
                maxi=max(maxi,res);
            }
            
            s.push(i);
        }
        
        while(s.empty()==false){
            long long ind=s.top();
            s.pop();
            long long res=arr[ind]*(s.empty()?n:n-s.top()-1);
            maxi=max(maxi,res);
        }
        
        return maxi;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends