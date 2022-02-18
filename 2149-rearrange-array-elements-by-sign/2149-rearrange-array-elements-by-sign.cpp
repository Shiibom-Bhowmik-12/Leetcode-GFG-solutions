class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ps,ng;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ng.emplace_back(nums[i]);
            }
            else{
                ps.emplace_back(nums[i]);
            }
        }
        
        vector<int> res;
        //bool flag1=true,flag2=false;
        for(int i=0;i<ps.size();i++){
                res.emplace_back(ps[i]);
                res.emplace_back(ng[i]);
        }
        
        return res;
    }
};