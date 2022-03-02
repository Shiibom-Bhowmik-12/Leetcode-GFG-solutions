// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string s)
    {
        // code here
    /*
        Initially considering that all the character are same in the string
        so there will be (n) * (n - 1) / 2 distinct strings after swap.
        e.g s = "abcde"
        for s[0]->a --> We can swap it with  b, c, d, and e ==> So distinct strings = 4
        for s[1]->b --> We can swap it with c, d, e ==> So distinct string = 3
        for s[2]->c --> We can swap it with  d, e ==> So distinct string = 2
        for s[3]->d --> We can swap it with e ==> So distinct string = 1
        for s[4]->e --> We swapped e with all characters earlier so no need to swap ==> Dist. string = 0;
        
        hence we get the formula 
            for string of length n of distinct character we can have
        ==>  ((n) * (n - 1)) / 2 distinct string after swap.
        */
        
        long long ans = (s.size() * (s.size() - 1)) / 2;
        long long arr[26] = {0};
        
        int y = 0;
        
        //Storing the frequencies of character like how many times they are occuring.
        for(char ch : s)
            arr[ch - 'a']++;
        
        for(int i = 0; i < 26; i++){
            if(arr[i] > 1){
                //Subtracting the count of repeating string.
                ans -= (arr[i] * (arr[i] - 1)) / 2;
                y++;
            }
        }
        
        //Will add +1 in ans because we have to consider one string from all repeated string 
        //as distinct string.
        return y == 0 ? ans : ans + 1;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends