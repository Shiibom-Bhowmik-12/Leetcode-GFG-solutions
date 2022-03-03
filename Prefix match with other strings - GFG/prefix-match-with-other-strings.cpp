// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
#define f(i,a,b) for(int i = a;i<b;i++)
struct Node {
  int freq;
  Node* child[26];
  Node(){
      freq = 1;
      f(i,0,26)child[i] = NULL;
  }
};
class Solution{   
public:
    Node* t = new Node();
    void insert(string s, Node* t){
        f(i,0, s.size()){
            int index = s[i] - 'a';
            if(!t->child[index]){
                t->child[index] = new Node();
            }else{
                t->child[index]->freq++;
            }
            t = t->child[index];
        }
    }
    int getfreq(string s, Node*t){
        f(i,0,s.size()){
            int index = s[i] - 'a';
            if(!t->child[index])return 0;
            t = t->child[index];
        }
        return t->freq;
    }
    int klengthpref(string arr[], int n, int k, string str){    
        string s = str.substr(0, k);
        f(i,0,n)insert(arr[i],t);
        return getfreq(s,t);
    }
    };

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends