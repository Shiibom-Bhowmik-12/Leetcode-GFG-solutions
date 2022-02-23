class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(auto x:nums){
            mp[x]++;
        }
        
        int maxi=INT_MIN;
        for(auto x:mp){
            if(x.second>maxi){
                maxi=x.second;
            }
        }
        
        int rees=0;
        for(auto x:mp){
            if(x.second==maxi){
                rees=x.first;
            }
        }
        
        return rees;
    }
};