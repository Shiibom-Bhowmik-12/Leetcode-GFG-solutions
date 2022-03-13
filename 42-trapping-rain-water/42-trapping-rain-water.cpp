class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_l(height.size(),0);
        vector<int> max_r(height.size(),0);
        
        int n=height.size();
        max_l[0]=height[0];
        max_r[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
            max_l[i]=max(max_l[i-1],height[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            max_r[i]=max(max_r[i+1],height[i]);
        }
        
        int sum_water=0;
        for(int i=0;i<n;i++){
            sum_water+=min(max_l[i],max_r[i])-height[i];
        }
        
        return sum_water;
    }
};