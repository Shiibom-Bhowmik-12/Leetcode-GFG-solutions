class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        
        unordered_set<int> st1,st2,check1,check2;
        vector<int> list1;
        vector<int> list2;
        
        for(auto x:nums1){
            st1.insert(x);
        }
        
        for(auto x:nums2){
            st2.insert(x);
            if(st1.find(x)==st1.end() and check1.find(x)==check1.end()){
                check1.insert(x);
                list1.emplace_back(x);
            }
        }
        
        for(auto x:nums1){
            if(st2.find(x)==st2.end() and check2.find(x)==check2.end()){
                check2.insert(x);
                list2.emplace_back(x);
            }
        }
        
        res.emplace_back(list2);
        res.emplace_back(list1);
        
        return res;
        
    }
};