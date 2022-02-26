class Solution {
public:
    long long smallestNumber(long long num) {
        auto s=to_string(num);//converting it to string for convininence
        
        //if the number is greater than 0, then we habe to sort the
        //digits in ascending order.If there are leading zeroes 
        //then we just have to swap the 0th position zero with the first 
        //non-zero digit.
        if(num>0){
            sort(s.begin(),s.end());
            
            //if there are leading zeroes then we run a loop to look for
            //non-zero digit.
            if(s[0]=='0'){
                int i=0;
                while(s[i]=='0'){
                    i++;
                }
                
                swap(s[i],s[0]);
            }
        }
        else{  
            //if the given number is less than 0, then we just sort the
            //given number in descending order.
            sort(s.begin()+1,s.end(),greater<char>());
        }
        
        return stoll(s);//returning the resultant from string to long long.
    }
};