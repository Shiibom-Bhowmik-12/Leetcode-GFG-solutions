class Solution {
public:
    int countElements(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mini and nums[i]<maxi){
                res++;
            }
        }
        
        return res;
    }
};