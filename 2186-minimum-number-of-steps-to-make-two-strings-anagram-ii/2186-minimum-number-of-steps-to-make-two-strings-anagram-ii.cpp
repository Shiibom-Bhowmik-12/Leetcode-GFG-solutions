class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        for(auto x:s){
            mp1[x]++;
        }
        
        for(auto x:t){
            mp2[x]++;
        }
        
        int c1=0;
        for(auto x:s){
            if(mp2.find(x)!=mp2.end() and mp2[x]>0){
                mp2[x]--;
            }
            else{
                c1++;
            }
        }
        
        for(auto x:t){
            if(mp1.find(x)!=mp1.end() and mp1[x]>0){
                mp1[x]--;
            }
            else{
                c1++;
            }
        }
        
        return c1;
    }
};