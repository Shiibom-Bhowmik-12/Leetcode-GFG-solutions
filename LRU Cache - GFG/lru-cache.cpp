// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
            node(int _key,int _val){
                key=_key;
                val=_val;
                next=NULL;
                prev=NULL;
            }
    };
    
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int capacity;
    unordered_map<int,node *> m;
    
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node *add_node){
        node *temp=head->next;
        add_node->next=temp;
        temp->prev=add_node;
        head->next=add_node;
        add_node->prev=head;
    }
    
    void delnode(node *del_node){
        node *delprev=del_node->prev;
        node *delnext=del_node->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            node *got=m[key];
            int res=got->val;
            m.erase(key);
            delnode(got);
            addnode(got);
            m[key]=head->next;
            return res;
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here 
        if(m.find(key)!=m.end()){
            node *got=m[key];
            m.erase(key);
            delnode(got);
        }
        
        if(m.size()==capacity){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends