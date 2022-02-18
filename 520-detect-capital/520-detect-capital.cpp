class Solution {
public:
    bool case1(string word){
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' and word[i]<='z'){
                return false;
            }
        }
        return true;
    }
    
    bool case2(string word){
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' and word[i]<='Z'){
                return false;
            }
        }
        
        return true;
    }
    
    bool case3(string word){
        bool flag=false;
        if(word[0]>='A' and word[0]<='Z'){
            flag=true;
        }
        for(int i=1;i<word.size();i++){
            if(flag==true and islower(word[i])){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    
    bool detectCapitalUse(string word) {
        if(case1(word) or case2(word) or case3(word)){
            return true;
        }
        return false;
    }
};