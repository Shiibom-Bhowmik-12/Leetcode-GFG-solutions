class Solution {
public:
    void solve(vector<int> ip,vector<int> op,set<vector<int>> &s){
        if(ip.size()==0){
            s.insert(op);
            return;
        }
        
        vector<int> op1=op;
        vector<int> op2=op;
        
        op2.emplace_back(ip[0]);
        ip.erase(ip.begin()+0);
        
        solve(ip,op1,s);
        solve(ip,op2,s);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        
        solve(nums,{},s);
        
        for(auto x:s){
            res.emplace_back(x);
        }
        
        return res;
    }
};