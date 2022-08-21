class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res=0,maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                res++;
                maxi=max(res,maxi);

            }
            else
            {
                res=0;
            }
        }
        
        return maxi;
    }
};