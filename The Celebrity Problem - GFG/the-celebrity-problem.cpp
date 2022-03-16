// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //M[i][j]==1 -> i knows j 
        //M[i][j]==0 -> j don't knows i
        int celeb=0;
        
        //traversing linearly to make our probable celebrity
        for(int i=1;i<n;i++){
            if(M[celeb][i]==1){
                celeb=i;
            }
        }
        
        //once we get our probable celeb we traverse trhought the array 
        //to check and be sure that we have got the right celebrity
        //so we check for false condition of being a celebrity.
        for(int i=0;i<n;i++){
            if(i!=celeb and (M[celeb][i]==1 or M[i][celeb]==0)){
                return -1;
            }
        }
        
        return celeb;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends