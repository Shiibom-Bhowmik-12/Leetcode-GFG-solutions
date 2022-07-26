class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        int maxi=a[0];
        int jump=1;
        int stair=a[0];
        
        if(n==1){
            return 0;
        }
        else if(a[0]==0){
            return -1;
        }
        for(int i=1;i<n;i++){
            if(i==n-1){
                // return jump;
                break;
            }
            
            maxi=max(maxi,i+a[i]);
            stair--;
            
            if(stair==0){
                jump++;
                
                if(i>=maxi){
                    return -1;
                }
                
                stair=maxi-i;
            }
        }
        
        return jump;
    }
};