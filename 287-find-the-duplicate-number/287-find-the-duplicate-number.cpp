class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        int res;
        
        for(auto x:nums){
            if(mp.find(x)!=mp.end()){
                res=x;
            }
            mp.insert(x);
        }
        
        return res;
    }
};