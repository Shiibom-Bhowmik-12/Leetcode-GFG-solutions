class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> s;
    
    SmallestInfiniteSet() {
        //contains all positive intergers within the range
       for(int i=1;i<=1000;i++)
        {
            pq.push(i);
            s.insert(i);
        }
    }
    
    //deleting the minimum
    int popSmallest() {
        if(pq.size()>0){
            int res=pq.top();
            s.erase(res);
            pq.pop();
            return res;
        }
        
        return -1;
    }
    
    //adding items into the min heap
    void addBack(int num) {
        if(s.find(num)==s.end()){
            pq.push(num);
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */