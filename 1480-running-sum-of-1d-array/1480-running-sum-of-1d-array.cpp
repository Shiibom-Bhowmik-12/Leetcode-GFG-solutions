class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        
        int k=0;
        for(auto x:nums){
            k+=x;
            res.emplace_back(k);
        }
        
        return res;
    }
};