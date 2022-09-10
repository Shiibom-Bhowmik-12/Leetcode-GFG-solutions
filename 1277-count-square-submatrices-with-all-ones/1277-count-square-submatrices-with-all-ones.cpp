class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        
        int dp[n][m];
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==1) dp[i][0]=1;
            else dp[i][0]=0;
        }
        
        for(int j=0;j<m;j++){
            if(matrix[0][j]==1) dp[0][j]=1;
            else dp[0][j]=0;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
            }
        }
        
        return sum;
    }
};