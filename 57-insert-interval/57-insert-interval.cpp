class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
         intervals.push_back(newInterval);
         vector<pair<int,int>> vp;
         
         for(int i=0;i<intervals.size();i++){
            vp.push_back({intervals[i][0],intervals[i][1]});
         }
         
         sort(vp.begin(),vp.end());
         
         int idx=0;
         for(int i=1;i<vp.size();i++){
             if(vp[idx].second >= vp[i].first){
                 vp[idx].second=max(vp[idx].second,vp[i].second);
                 vp[idx].first=min(vp[idx].first,vp[i].first);
             }
             else{
                 idx++;
                 vp[idx]=vp[i];
             }
         }
         
         vector<vector<int>> v;
         for(int i=0;i<=idx;i++){
             vector<int> res;
             res.push_back(vp[i].first);
             res.push_back(vp[i].second);
             v.push_back(res);
         }
         
         return v;
    }
};