class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i=0;
        for(;i<nums.size();i++){
            int t1=nums[i];
            int t2=INT_MIN;
            int j=i+1;
            for(;j<nums.size();j++){
                if(nums[j]>=0 and nums[j]==nums[j-1]+1){
                    t2=nums[j];
                    continue;
                }
                else if(nums[j]<0 and nums[j]==nums[j-1]+1){
                    t2=nums[j];
                    continue;
                }
                else
                    break;
            }
            string s=to_string(t1);
            if(t2!=INT_MIN){
                s+="->"+to_string(t2);
            }
            res.emplace_back(s);
            i=j-1;
        }
        
        return res;
    }
};