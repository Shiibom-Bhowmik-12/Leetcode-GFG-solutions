class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int copy_k=k;
        
        for(int i=0;i<num.size();i++){
            while(!s.empty() and s.top()-'0'>num[i]-'0' and k!=0){
                s.pop();
                k--;
            }
            
            s.push(num[i]);
        }
        
        while(k!=0 and !s.empty()){
            s.pop();
            k--;
        }
        
        string res="";
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        
        if(res==""){
            return "0";
        }
        
        
        int i=0;
        while(i<res.size() and res[i]=='0'){
            i++;
        }
        
        res=res.substr(i);
        
        if(res==""){
            return "0";
        }
        
        return res;
    }
};