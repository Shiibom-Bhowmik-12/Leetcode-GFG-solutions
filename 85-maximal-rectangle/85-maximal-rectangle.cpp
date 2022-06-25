class Solution {
public:
    int largestHistogram(vector<int> v,int n){
        stack<int> s;
        int res=INT_MIN;
        
        for(int i=0;i<n;i++){
            while(!s.empty() and v[s.top()]>=v[i]){
                int ind=s.top();
                s.pop();
                int curr=v[ind]*(s.empty()?i:i-s.top()-1);
                res=max(res,curr);
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            int ind=s.top();
            s.pop();
            int curr=v[ind]*(s.empty()?n:n-s.top()-1);
            res=max(res,curr);
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        
        for(int i=0;i<matrix.size();i++){
            vector<int> res;
            for(int j=0;j<matrix[i].size();j++){
                int k=matrix[i][j]-'0';
                res.emplace_back(k);
            }
            v.emplace_back(res);
        }
        
        int res=largestHistogram(v[0],matrix[0].size());
        
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1){
                    v[i][j]+=v[i-1][j];
                }
            }
            res=max(res,largestHistogram(v[i],v[0].size()));
        }
        
        return res;
    }
};