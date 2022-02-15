class Solution {
public:
    int compress(vector<char>& chars) {
        int c=1;
        string s="";
        
        if(chars.size()==1){
            return 1;
        }
        
//         we perform as said in the question
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]!=chars[i-1]){
                if(c==1){
                    s+=chars[i-1];
                    c=1;
                }
                else{
                    s+=chars[i-1];
                    s+=to_string(c);
                    c=1;
                }
            }
            else{
                c++;
            }
        }
        
        if(c==1){//if the last character has frequency 1 then we only add char
            s+=chars[chars.size()-1];
        }
        else{//else we add char along with its frequency
            s+=chars[chars.size()-1];
            s+=to_string(c);
        }
 
        
        chars.clear();//we clear the vector before we push back elements into it
        for(int i=0;i<s.size();i++){
            chars.emplace_back(s[i]);
        }
        
        return chars.size();//returning the char size
    }
};