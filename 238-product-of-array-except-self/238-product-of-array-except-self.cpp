class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> op;
        int pro=1;
        
        for(int i=0;i<nums.size();i++){
            pro*=nums[i];
            op.push_back(pro);
        }
        
        pro=1;
        for(int i=nums.size()-1;i>0;i--){
            op[i]=pro*op[i-1];
            pro*=nums[i];
        }
        
        op[0]=pro;
        return op;
    }
};