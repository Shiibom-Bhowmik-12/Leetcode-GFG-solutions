class MedianFinder {
public:
    priority_queue<int> s_maxheap;
    priority_queue<int,vector<int>,greater<int>> g_minheap;
    MedianFinder() {}
    
    void balance(int x){
        if(s_maxheap.size()>g_minheap.size()){
            if(s_maxheap.top()>x){
                g_minheap.push(s_maxheap.top());
                s_maxheap.pop();
                s_maxheap.push(x);
            }
            else{
                g_minheap.push(x);
            }
        }else{
            if(s_maxheap.top()>=x){
                s_maxheap.push(x);
            }
            else{
                g_minheap.push(x);
                s_maxheap.push(g_minheap.top());
                g_minheap.pop();
            }
        }
    }
    
    void addNum(int num) {
        if(s_maxheap.size()==0){
            s_maxheap.push(num);
            return;
        }
        
        balance(num);
    }
    
    double findMedian() {
        if(s_maxheap.size()==g_minheap.size()){
            return ((s_maxheap.top()+g_minheap.top())/2.0);
        }
        else{
            return s_maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */