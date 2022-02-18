class Solution {
public:
    static bool comp(pair<int,string> &p1,pair<int,string> &p2){
        if(p1.first==p2.first){
            return (p1.second<p2.second);
        }
        
        return p1.first>p2.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        
        //string frequency along with the words into the map
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        //creating vector to sort according to the given conditions
        vector<pair<int,string>> vp;
        
        //inserting into the vector so that we can sort it
        for(auto x:mp){
            vp.push_back({x.second,x.first});
        }

        sort(vp.begin(),vp.end(),comp);//using comarator to make sure about the      
                                       //lexicographical order

        vector<string> v;
        for(int i=0;i<vp.size();i++){
            //taking k top elements after sorting in descending order of frequency
            if(k==0){
               break;
            }
            v.emplace_back(vp[i].second);
            k--;
        }
    
       return v;
  }
};