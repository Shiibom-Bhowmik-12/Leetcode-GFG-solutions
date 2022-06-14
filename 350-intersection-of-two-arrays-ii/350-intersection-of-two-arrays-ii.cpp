class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;
        
        for(auto x:nums1){
            mp[x]++;
        }
        
        for(auto x:nums2){
            if(mp.find(x)!=mp.end() and mp[x]>=1){
                res.emplace_back(x);
                mp[x]--;
            }
        }
        
        return res;
    }
};