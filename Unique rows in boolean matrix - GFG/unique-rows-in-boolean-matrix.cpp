// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
struct Node{
    Node *links[2];
    bool flag=false;
    
    bool iscontainsKey(int x){
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
                    if(!node->iscontainsKey(v[i])){
                        node->put(v[i],new Node());
                    }
                    
                    node=node->get(v[i]);
                }
                
                node->setEnd();
            }
            
            bool search(vector<int> v){
                Node *node=root;
                for(int i=0;i<v.size();i++){
                    if(!node->iscontainsKey(v[i])){
                        return false;
                    }
                    
                    node=node->get(v[i]);
                }
                
                return node->getEnd();
            }
};

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
   //Your code here
   vector<vector<int>> res;
   Trie *obj=new Trie();
   
   for(int i=0;i<row;i++){
       vector<int> v;
       for(int j=0;j<col;j++){
           v.emplace_back(M[i][j]);
       }
       
       if(obj->search(v)){
           continue;
       }
       
       obj->insert(v);
       res.emplace_back(v);
   }
   
   return res;
}