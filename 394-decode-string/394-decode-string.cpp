class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> string_stack;
        
        int curr_num=0;
        string curr_str="";
        
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                curr_num=curr_num*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                num_stack.push(curr_num);
                curr_num=0;
                
                string_stack.push(curr_str);
                curr_str="";
            }
            else if(s[i]==']'){
                int k=num_stack.top();
                num_stack.pop();
                
                string prev_str=string_stack.top();
                string_stack.pop();
                
                while(k--){
                    prev_str+=curr_str;
                }
                
                curr_str=prev_str;
            }
            else{
                curr_str+=s[i];
            }
        }
        
        return curr_str;
    }
};