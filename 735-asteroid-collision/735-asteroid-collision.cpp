class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> s;
        
        for(auto x:asteroids){
            bool flag=true;//insertion condition of curent element
            
            while(!s.empty() and (s.top()>0 and x<0)){
                //when top is greater then the incoming -> incoming explodes top remains
                //thats why flag is made false
                if(s.top()>abs(x)){
                    flag=false;
                    break;
                }
                
                //when top is smaller then the incoming -> top explodes incoming
                //remains and inserted into the stack
                else if(s.top()<abs(x)){
                    s.pop();
                }
                
                //when top and incoming size is same then both explodes and the incoming 
                //need not to be inserted
                else{
                    flag=false;
                    s.pop();
                    break;
                }
            }
            
            if(flag){
                s.push(x);
            }
        }
        
        while(!s.empty()){
            res.emplace_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};