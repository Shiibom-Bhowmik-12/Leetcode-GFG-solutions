// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> m){
        //code here
     pair<int, int> ans;
       int c = m[0].size();
       int r = m.size();
       char d = 'r';
       
       int i=0,j=0;
       while(i<r && j<c && i>=0 && j>=0)
       {
           if(m[i][j]==0 && d=='r') j++;
           else if(m[i][j]==0 && d=='l') j--;
           else if(m[i][j]==0 && d=='u') i--;
           else if(m[i][j]==0 && d=='d') i++;
           else if(m[i][j]==1 && d=='d')
           { m[i][j]=0; j--; d='l';}
           else if(m[i][j]==1 && d=='r')
           { m[i][j]=0; i++; d='d';}
           else if(m[i][j]==1 && d=='u')
           { m[i][j]=0; j++; d='r';}
           else if(m[i][j]==1 && d=='l')
           { m[i][j]=0; i--; d='u';}
       }
   
       if(i>=r) i--;  if(j>=c) j--;
       if(i<0) i++;    if(j<0) j++;
       
       ans.first=i; ans.second=j;
       return ans; 
   }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends