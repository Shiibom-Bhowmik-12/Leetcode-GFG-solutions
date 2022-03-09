// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
struct Node{
    Node *links[2];
    bool flag=false;
    
    bool containsKey(int x){
        return (links[x]!=NULL);
    }
    
    void put(int x,Node *node){
        links[x]=node;
    }
    
    Node *get(int x){
        return links[x];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool getEnd(){
        return flag;
    }
};

class Trie{
    private:Node *root;
    public:
            Trie(){
                root=new Node();
            }
            
            void insert(vector<int> v){
                Node *node=root;
                for(int i=0;i<v.size();i++){
                    if(!node->containsKey(v[i])){
                        node->put(v[i],new Node());
                    }
                    
                    node=node->get(v[i]);
                }
                
                node->setEnd();
            }
            
            bool ispresent(vector<int> v){
                Node *node=root;
                for(int i=0;i<v.size();i++){
                    if(node->containsKey(v[i])){
                       node=node->get(v[i]); 
                    }
                    else{
                        return false;
                    }
                }
                
                return node->getEnd();
            }
};

class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{ 
    // Your code here
    Trie *obj=new Trie();
    vector<int> res;
    
    for(int i=0;i<M;i++){
        vector<int> v;
        for(int j=0;j<N;j++){
            v.emplace_back(matrix[i][j]);
        }
        
        if(obj->ispresent(v)){
            res.emplace_back(i);
        }
        obj->insert(v);
    }
    
    return res;
} 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


  // } Driver Code Ends