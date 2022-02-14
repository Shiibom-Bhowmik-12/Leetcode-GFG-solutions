class LRUCache {
public:
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
        int cap;
        unordered_map<int,node *> m;  
    
        LRUCache(int capacity) {
            cap=capacity;
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
    
        int get(int key) {
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

        void put(int key, int value) {
               if(m.find(key)!=m.end()){
                    node *got=m[key];
                    m.erase(key);
                    delnode(got);
                }

                if(m.size()==cap){
                    m.erase(tail->prev->key);
                    delnode(tail->prev);
                }

                addnode(new node(key,value));
                m[key]=head->next;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */