class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                res.emplace_back(mp[target-nums[i]]);
                res.emplace_back(i);
                break;
            }
            
            mp[nums[i]]=i;
        }
        
        return res;
    }
};