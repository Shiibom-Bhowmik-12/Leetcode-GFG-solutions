// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
struct Node{
  Node *links[26];
  int start=0;
  int end=0;
  
  bool iscontainskey(char ch){
      return links[ch-'a'];
  }
  
  void put(char ch,Node *node){
      links[ch-'a']=node;
  }
  
  Node *get(char ch){
      return links[ch-'a'];
  }
  
  void increase_start(){
      start++;
  }
  
  void increase_end(){
      end++;
  }
  
  int return_start(){
      return start;
  }
  
  int return_end(){
      return end;
  }
};

class Trie{
    private:Node *root;
    public:
           Trie(){
              root=new Node(); 
           }
           
           void insert(string word){
               Node *node=root;
               for(int i=0;i<word.size();i++){
                   if(!node->iscontainskey(word[i])){
                       node->put(word[i],new Node());
                   }
                   node->increase_start();
                   node=node->get(word[i]);
               }
               
               node->increase_end();
           }
           
           string find(string word){
               Node *node=root;
               string ans="";
               for(int i=0;i<word.size();i++){
                   ans+=word[i];
                   node=node->get(word[i]);
                   if(node->return_start()==1){
                       break;
                   }
               }
               
               return ans;
           }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        vector<string> res;
        Trie *obj=new Trie();
        for(int i=0;i<n;i++){
            obj->insert(arr[i]);
        }
        
        for(int i=0;i<n;i++){
            res.push_back(obj->find(arr[i]));
        }
        
        return res;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends