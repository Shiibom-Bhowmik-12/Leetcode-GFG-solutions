class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> res;
        map<int,vector<int>> mp;
        
        for(auto x:nums){
            string temp=to_string(x);
            int a=0;
            
            for(auto x:temp){
                int y=x-'0';
                a=a*10 + mapping[y];
            }
            
            mp[a].emplace_back(x);
        }
        
        for(auto x:mp){
            for(auto y:x.second){
                res.emplace_back(y);
            }
        }
        
        return res;
    }
};