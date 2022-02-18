class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        priority_queue<pair<int,int>> maxheap;
        
        for(int i=0;i<arr.size();i++){
            maxheap.push({abs(arr[i]-x),arr[i]});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        
        while(!maxheap.empty()){
            v.emplace_back(maxheap.top().second);
            maxheap.pop();
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};