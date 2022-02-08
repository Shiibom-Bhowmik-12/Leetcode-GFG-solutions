class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> s;
        int curr=0,res=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            while(s.empty()==false && heights[s.top()]>=heights[i])
            {
                int k=s.top();
                s.pop();
                curr=heights[k]*(s.empty()?i:i-s.top()-1);
                res=max(res,curr);
            }
            s.push(i);
        }
        
        while(!s.empty())
        {
            int p=s.top();
            s.pop();
            curr=heights[p]*(s.empty()?n:n-s.top()-1);
            res=max(res,curr);
        }
        
        return res;
                
    }
};