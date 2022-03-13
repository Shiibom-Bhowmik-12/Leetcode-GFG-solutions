// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        vector<int> max_l(n,0);
        vector<int> max_r(n,0);
        
        // int n=height.size();
        max_l[0]=height[0];
        max_r[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
            max_l[i]=max(max_l[i-1],height[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            max_r[i]=max(max_r[i+1],height[i]);
        }
        
        long long sum_water=0;
        for(int i=0;i<n;i++){
            sum_water+=min(max_l[i],max_r[i])-height[i];
        }
        
        return sum_water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends