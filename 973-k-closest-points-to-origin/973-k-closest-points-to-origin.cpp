class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        
        priority_queue<pair<int,pair<int,int>>> maxheap;
        for(int i=0;i<points.size();i++){
            maxheap.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),{points[i]                                [0],points[i][1]}});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        
        while(!maxheap.empty()){
            vector<int> p;
            auto temp=maxheap.top().second;
            maxheap.pop();
            p.emplace_back(temp.first);
            p.emplace_back(temp.second);
            v.emplace_back(p);
        }
        
        return v;
    }
};