class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> s;
    int maxfreq=0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        s[freq[val]].push(val);
        maxfreq=max(maxfreq,freq[val]);
    }
    
    int pop() {
        int x=s[maxfreq].top();
        s[maxfreq].pop();
        
        if(s[maxfreq].empty()){
            maxfreq--;
        }
        
        freq[x]--;
        if(freq[x]==0){
            freq.erase(x);
        }
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */