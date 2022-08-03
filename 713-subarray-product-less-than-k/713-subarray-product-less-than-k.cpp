class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        
        int p=1;
        int res=0;
        
        int start=0,end=0;
        
        while(end<nums.size()){
            p*=nums[end];
            
            while(p>=k){
                p/=nums[start];
                start++;
            }
            
            res+=1+(end-start);
            end++;
        }
        
        return res;
    }
};