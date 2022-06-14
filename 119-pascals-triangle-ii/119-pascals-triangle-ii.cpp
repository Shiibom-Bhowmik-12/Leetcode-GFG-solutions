class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        
        vector<int> res;
        long long val=1;
        res.emplace_back(val);
        for(long long i=0;i<rowIndex;i++){
            val*=rowIndex-i;
            val/=i+1;
            res.emplace_back(val);
        }
        
        return res;
    }
};