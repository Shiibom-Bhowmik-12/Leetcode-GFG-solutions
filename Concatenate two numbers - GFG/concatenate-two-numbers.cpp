// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:

    long long countPairs(int N, int X, vector<int> numbers){
            long long int ans=0;
            unordered_map<string ,int>mp;
            for(auto i:numbers)
            {
               mp[to_string(i)]++;
            }
            string s=to_string(X);
            for(int i=1;i<s.size();i++)
            {
                string first=s.substr(0,i);
                string second=s.substr(i);
                if(first==second)
                    ans+=mp[first]*(mp[second]-1);
                else 
                    ans+=mp[first]*mp[second];
            }
            return ans;
    }
}; 

// 1.first convert all vector element into string using to_string function.

// 2. convert X into string.

// 3. take a loop of size X.

// 4. take two string first and second within loop .

// 5. check substring of X if it exist then multiply the values.

//  such as s="12345"   first=1 and second=2345

// if 1 and 2345 pairs exists in map then multiply how much time 1 occurs and how much time 2345 occurs .

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends