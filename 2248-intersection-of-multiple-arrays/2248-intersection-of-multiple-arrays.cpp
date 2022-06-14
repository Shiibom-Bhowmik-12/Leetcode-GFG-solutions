class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        unordered_map<int,int> mp;
        vector<int> res;
        if(nums.size()==1){
            res=nums[0];
            sort(res.begin(),res.end());
            return res;
        }
        
        for(int i=0;i<nums[0].size();i++){
            mp[nums[0][i]]++;
        }
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(mp[nums[i][j]]==i){
                    mp[nums[i][j]]=i+1;
                    
                    if(i==nums.size()-1 and mp[nums[i][j]]==nums.size()){
                        res.emplace_back(nums[i][j]);
                        mp.erase(nums[i][j]);
                    }
                }
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};