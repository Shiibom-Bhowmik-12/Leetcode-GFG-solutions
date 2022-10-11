class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        vector<int> res;
        stack<int> s;
        s.push(tem.size()-1);
        // res.push_back(0);
        
        for(int i=tem.size()-1;i>=0;i--){
            while(!s.empty() and tem[i]>=tem[s.top()]){
                s.pop();
            }
            
            int ans=s.empty()?0:s.top()-i;
            res.push_back(ans);
            s.push(i);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};