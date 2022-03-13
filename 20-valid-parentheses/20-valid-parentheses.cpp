class Solution {
public:
   bool matching(char c1,char c2)
    {
        return ((c1=='(' && c2==')') || 
                (c1=='{' && c2=='}') || 
                (c1=='[' && c2==']'));
    }
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()==true)
                {
                    return false;
                }
                else if(matching(st.top(),s[i])==false)
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return (st.empty()==true);
    }
};