// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
     int getMaxArea(int arr[], int n)
    {
        // Your code here
        stack<int> s;
        int maxi=0;
        
        for(int i=0;i<n;i++){
            while(s.empty()==false and arr[s.top()]>=arr[i]){
                int ind=s.top();
                s.pop();
                int res=arr[ind]*(s.empty()?i:i-s.top()-1);
                maxi=max(maxi,res);
            }
            
            s.push(i);
        }
        
        while(s.empty()==false){
            int ind=s.top();
            s.pop();
            int res=arr[ind]*(s.empty()?n:n-s.top()-1);
            maxi=max(maxi,res);
        }
        
        return maxi;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxi=getMaxArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    M[i][j]+=M[i-1][j];
                }
            }
            maxi=max(maxi,getMaxArea(M[i],m));
        }
        
        return maxi;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends