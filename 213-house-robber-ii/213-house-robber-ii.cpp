class Solution {
public:
    int maxi_1(vector<int> nums,int n){
        vector<int> dp(n,0);
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++){
            int pick=nums[i];
            
            if(i>1){
                pick+=dp[i-2];
            }
            
            int not_pick=0+dp[i-1];
            
            dp[i]=max(pick,not_pick);
        }
        
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        
        if(nums.size()==1){
            return nums[0];
        }
        
        int n=nums.size();
        
        vector<int> n1,n2;
        
        for(int i=1;i<nums.size();i++){
            n1.emplace_back(nums[i]);
        }
        
        for(int i=0;i<nums.size()-1;i++){
            n2.emplace_back(nums[i]);
        }
        
        int dp1=maxi_1(n1,n-1);
        int dp2=maxi_1(n2,n-1);
        
        return max(dp1,dp2);
    }
};