class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        map<vector<int>,int> s;
        
        for(int i=0;i<grid.size();i++){
            vector<int> v;
            for(int j=0;j<grid[i].size();j++){
                v.emplace_back(grid[j][i]);
            }
            
            s[v]++;
        }
        
        int c=0;
        for(int i=0;i<grid.size();i++){
            vector<int> v;
            for(int j=0;j<grid[i].size();j++){
                v.emplace_back(grid[i][j]);
            }
            
            if(s.find(v)!=s.end()){
                c+=s[v];
            }
        }
        
        return c;
    }
};