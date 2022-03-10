// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int seg(char ch){
        if(ch=='0' or ch=='6'){
            return 6;
        }
        else if(ch=='1'){
            return 2;
        }
        else if(ch=='2' or ch=='3' or ch=='5' or ch=='9'){
            return 5;
        }
        else if(ch=='4'){
            return 4;
        }
        else if(ch=='7'){
            return 3;
        }
        else if(ch=='8'){
            return 7;
        }
    }
    
    string sevenSegments(string S, int N) {
        // code here
int symbol[]={6,2,5,5,4,5,6,3,7,5};
       int sum=0;
       string ans="";
       for(int i=0;i<N;i++)
       {
           int z=S[i]-'0';
           sum+=symbol[z];
       }
       int a[N];
       for(int i=0;i<N;i++)
       {
           a[i]=2;
           sum-=2;
       }
       int i=0;
       while(sum>=4 && i<N)
       {
           a[i]=6;
           sum-=4;
           i++;
       }
       int j=N-1;
       while(sum>0 && j>=0)
       {
           int req=7-a[j];
           a[j]+=min(req,sum);
           sum-=min(req,sum);
           j--;
       }
       //Final Traversal 
       for(i=0;i<N;i++)
       {
           if(a[i]==6)
           ans+='0';
           else if(a[i]==2)
           ans+='1';
           else if(a[i]==5)
           ans+='2';
           else if(a[i]==3)
           ans+='7';
           else if(a[i]==4)
           ans+='4';
           else
           ans+='8';
           
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends