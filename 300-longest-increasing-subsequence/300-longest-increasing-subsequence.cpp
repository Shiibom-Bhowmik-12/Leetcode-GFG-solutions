class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
   int n = nums.size();
		
		 //Binary Search
        vector<int> v; //it doesn't store LIS but it's length equal to LIS
        v.push_back(nums[0]);
        
        for(int i=1;i<n; i++)
        {
            int j = v.size();
            
            if(nums[i] > v[j-1]) v.push_back(nums[i]);
            else
            {
                int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                if(idx<j) v[idx] = nums[i];
            }
        }
        
        return v.size();
    }
};