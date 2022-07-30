class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long s=0,c=0;
        
        for(auto x:nums){
            if(x==0){
                c++;
                s+=c;
            }
            else{
                c=0;
            }
        }
        
        return s;
    }
};