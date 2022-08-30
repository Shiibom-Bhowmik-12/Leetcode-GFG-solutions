class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closestsum=nums[0]+nums[1]+nums[nums.size()-1];
        
        for(int i=0;i<nums.size()-2;i++){
            int lo=i+1,hi=nums.size()-1;
            while(lo<hi){
                int curr=nums[i]+nums[lo]+nums[hi];
                if(curr > target){
                    hi--;
                }
                else{
                    lo++;
                }
                
                if(abs(closestsum-target) > abs(curr-target)){
                    closestsum=curr;
                }
            }
        }
        
        return closestsum;
    }
};