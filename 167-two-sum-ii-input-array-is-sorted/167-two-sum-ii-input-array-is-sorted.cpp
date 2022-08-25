class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        
        int lo=0,hi=numbers.size()-1;
        
        while(lo<hi){
            if(numbers[lo]+numbers[hi] == target){
                res.emplace_back(lo+1);
                res.emplace_back(hi+1);
                break;
            }
            else if(numbers[lo]+numbers[hi] < target){
                lo++;
            }
            else{
                hi--;
            }
        }
        
        return res;
    }
};