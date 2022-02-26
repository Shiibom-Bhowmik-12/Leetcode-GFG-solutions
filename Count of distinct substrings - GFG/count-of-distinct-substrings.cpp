// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends


/*You are required to complete this method */
struct Node{
    Node *links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void *put(char ch,Node *node){
        links[ch-'a']=node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

int countDistinctSubstring(string s)
{
    //Your code here
    Node *root=new Node();
    int cnt=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        Node *node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                node->put(s[j],new Node());
                cnt++;
            }
            
            node=node->get(s[j]);
        }
        node->setEnd();
    }
    
    return cnt+1;
}