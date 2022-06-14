class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1,mp2;
        int c=0;
        
        for(auto x:words1){
            mp1[x]++;
        }
        
        for(auto x:words2){
            mp2[x]++;
        }
        
        for(auto x:mp1){
            if(mp2.find(x.first)!=mp2.end() and (x.second==1 and mp2[x.first]==1)){
                c++;
            }
        }
        
        return c;
    }
};