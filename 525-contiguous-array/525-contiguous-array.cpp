class Solution {
public:
    int maxSubZero(vector<int> v){
        int pre=0,res=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<v.size();i++){
            pre+=v[i];
            
            if(pre==0){
                res=i+1;
            }
            
            if(mp.find(pre)!=mp.end()){
                res=max(res,i-mp[pre]);
            }
            
            if(mp.find(pre)==mp.end()){
                mp[pre]=i;
            }
        }
        
        return res;
    }
    
    int findMaxLength(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        
        return (maxSubZero(nums));
    }
};