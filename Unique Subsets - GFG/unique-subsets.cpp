// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(vector<int> arr,set<vector<int>> &vs,vector<int> res){
        if(arr.size()==0){
            vs.insert(res);
            return;
        }
        
        vector<int> k1=res;
        vector<int> k2=res;
        
        k2.emplace_back(arr[0]);
        arr.erase(arr.begin()+0);
        
        solve(arr,vs,k1);
        solve(arr,vs,k2);
    }
    
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>> v;
        if(n==0){
            return v;
        }
        sort(arr.begin(),arr.end());
        vector<int> res;
        set<vector<int>> vs;
        solve(arr,vs,res);
        
        for(auto x:vs){
            v.emplace_back(x);
        }
        
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends