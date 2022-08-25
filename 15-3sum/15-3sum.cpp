class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 or (i>0 and nums[i]!=nums[i-1])){
                int lo=i+1,hi=nums.size()-1;
                int sum=0-nums[i];
                
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                        vector<int> v;
                        v.emplace_back(nums[i]);
                        v.emplace_back(nums[lo]);
                        v.emplace_back(nums[hi]);
                        res.emplace_back(v);
                        
                        while(lo<hi and nums[lo]==nums[lo+1]){
                            lo++;
                        }
                        
                        while(lo<hi and nums[hi]==nums[hi-1]){
                            hi--;
                        }
                        
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi] <sum){
                        lo++;
                    }
                    else{
                        hi--;
                    }
                }
            }
        }
        
        return res;
    }
};