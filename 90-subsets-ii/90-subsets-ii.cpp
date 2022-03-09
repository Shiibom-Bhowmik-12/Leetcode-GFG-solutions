class Solution {
public:
    void subset(vector<int> op,set<vector<int>> &s,vector<int> nums){
        if(nums.size()==0){
            s.insert(op);
            return;
        }
        
        vector<int> op1=op;
        vector<int> op2=op;
        op2.emplace_back(nums[0]);
        nums.erase(nums.begin()+0);
        subset(op1,s,nums);
        subset(op2,s,nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        
        sort(nums.begin(),nums.end());
        subset({},s,nums);
        
        for(auto x:s){
            res.emplace_back(x);
        }
        
        return res;
    }
};