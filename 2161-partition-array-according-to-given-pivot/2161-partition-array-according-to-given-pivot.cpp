class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        
        vector<int> less,more;
        int c=0;
        
        for(auto x:nums){
            if(x==pivot){
                c++;
            }
            
            if(x<pivot){
                less.emplace_back(x);
            }
            else if(x>pivot){
                more.emplace_back(x);
            }
        }
        
        for(auto x:less){
            res.emplace_back(x);
        }
        
        while(c--){
            res.emplace_back(pivot);
        }
        
        for(auto x:more){
            res.emplace_back(x);
        }
        
        return res;
    }
};