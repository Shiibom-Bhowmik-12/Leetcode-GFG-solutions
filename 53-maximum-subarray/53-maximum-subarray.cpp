class Solution {
public:
    int maxSubArray(vector<int>& nums) {
                int res=nums[0];
        int max_end=nums[0];
            
        for(int i=1;i<nums.size();i++){
            max_end=max(nums[i],max_end+nums[i]);
            res=max(res,max_end);
        }
        
        return res;
    }
};