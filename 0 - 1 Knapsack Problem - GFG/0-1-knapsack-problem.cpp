// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int t[1001][1001];
    int knapSack_1(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int t[n+1][W+1];
    //   for(int i=0;i<n+1;i++){
    //       for(int j=0;j<W+1;j++){
    //           if(i==0 or j==0){
    //               t[i][j]=0;
    //           }
    //       }
    //   }
       
    //   //i->n , j->W
    //   for(int i=1;i<n+1;i++){
    //       for(int j=1;j<W+1;j++){
    //           if(wt[i-1]<=j){
    //               t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
    //           }
    //           else{
    //               t[i][j]=t[i-1][j];
    //           }
    //       }
    //   }
       
    //   return t[n][W];
       if(n==0 or W==0){
           return 0;
       }
       
       if(t[n][W]!=-1){
           return t[n][W];
       }
       
       if(wt[n-1]<=W){
           return t[n][W]=max(val[n-1]+knapSack_1(W-wt[n-1],wt,val,n-1),knapSack_1(W,wt,val,n-1));
       }
       else{
           return t[n][W]=knapSack_1(W,wt,val,n-1);
       }
    
    }
    
    int knapSack(int W, int wt[], int val[], int n){
      memset(t,-1,sizeof(t));
      return knapSack_1(W,wt,val,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends