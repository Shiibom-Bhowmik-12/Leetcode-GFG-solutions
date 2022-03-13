class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int c=0;
        int res=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                c++;
                res=max(res,c);
            }
            else if(s[i]==')'){
                st.pop();
                c--;
            }
        }
        
        return res;
    }
};