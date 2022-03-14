// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

struct Node{
    Node *links[26];
    vector<string> res;
    
    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    
    void setres(string word){
        res.push_back(word);
    }
    
    vector<string> getres(){
        return res;
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
                   if(!node->containskey(word[i])){
                       node->put(word[i],new Node());
                   }
                   
                   node=node->get(word[i]);
                   node->setres(word);
               }
           }
           
           vector<string> getcontacts(string word){
               Node *node=root;
               for(int i=0;i<word.size();i++){
                   if(node->containskey(word[i])){
                       node=node->get(word[i]);
                   }
                   else{
                       return {"0"};
                   }
               }
               
               return node->getres();
           }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> v;
        set<string> st;
        Trie *obj=new Trie();
        
        for(int i=0;i<n;i++){
            st.insert(contact[i]);
        }
        
        for(auto it:st){
            obj->insert(it);
        }
        
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            
            vector<string> k=obj->getcontacts(temp);
            v.push_back(k);
        }
        
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends