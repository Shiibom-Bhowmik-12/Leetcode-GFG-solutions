class Solution {
public:
    int maxSubarraySum(vector<int> arr,int n){
        int maxSum=arr[0];
        int pre=arr[0];
        
        for(int i=1;i<n;i++){
            pre=max(arr[i],pre+arr[i]);
            maxSum=max(maxSum,pre);
        }
        
        return maxSum;
    }
    
    int maxSubarraySumCircular(vector<int>& arr) {
        int n=arr.size();
        int fullSum=maxSubarraySum(arr,n);
        
        if(fullSum<0){
            return fullSum;
        }
        
        int pre=0;
        
        for(int i=0;i<n;i++){
            pre+=arr[i];
            arr[i]=-arr[i];
        }
        
        int maxCircularSum=pre+maxSubarraySum(arr,n);
        
        return max(maxCircularSum,fullSum);          
    }
};