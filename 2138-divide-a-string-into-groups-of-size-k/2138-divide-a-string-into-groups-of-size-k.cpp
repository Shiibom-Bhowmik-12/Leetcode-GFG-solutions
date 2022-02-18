class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string res="";
        int temp=k;
        vector<string> vs;
        
        for(int i=0;i<s.size();i++){
            if(temp==0 and i<s.size()){
                vs.emplace_back(res);
                temp=k;
                res.clear();
            }
            res+=s[i];
            temp--;
        }
        
        if(temp>0){
            while(temp--){
                res+=fill;
            }
        }
        
        vs.emplace_back(res);
        return vs;
    }
};