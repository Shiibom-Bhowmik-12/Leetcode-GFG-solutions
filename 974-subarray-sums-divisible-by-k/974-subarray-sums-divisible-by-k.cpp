class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int count=0;
        int pre=0;
        int mod=0;
        mp[0]=1;
        
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            mod=pre%k;
            
            if(mod<0){
                mod+=k;
            }
            
            if(mp.find(mod)==mp.end()){
                mp[mod]=0;
            }
            
            mp[mod]++;
            count+=mp[mod]-1;  
        }
        
        return count;
    }
};