class Solution {
public:
    int count_subsetsum(vector<int> nums,int sum){
        // int mod=1e9+7;
        int n=nums.size();
        int dp[n+1][sum+1];
        
        int zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
        }
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]>j or nums[i-1]==0){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        
            return dp[n][sum]*pow(2,zero);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        int real_sum=(target+sum)/2;
        
        if(target+sum < 0 or (target+sum)%2!=0){
            return 0;
        }
        
        return count_subsetsum(nums,real_sum);            
    }
};