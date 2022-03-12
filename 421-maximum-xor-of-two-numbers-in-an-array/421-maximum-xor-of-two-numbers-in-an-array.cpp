struct Node{
    Node *links[2];
    
    bool containskey(int x){
        return (links[x]!=NULL);
    }
    
    Node *get(int x){
        return links[x];
    }
    
    void put(int x,Node *node){
        links[x]=node;
    }
};

class Trie{
    private:Node *root;
    public:
            Trie(){
                root=new Node();
            }
    
            void insert(int num){
                Node *node=root;
                
                for(int i=31;i>=0;i--){
                    int bit=(num>>i)&1;//converting it into bit so that it can stored in Trie.
                    if(!node->containskey(bit)){//if the ith bit of the number is not present then store it in the trie.
                        node->put(bit,new Node());
                    }
                    
                    node=node->get(bit);//go the reference trie node for further operations.
                }
            }
    
            int findMax(int num){
                Node *node=root;
                int maxval=0;
                
                for(int i=31;i>=0;i--){
                    int bit=(num>>i)&1;//converting it into bit so that it can checked whther its opp. bit is present in trie or not. If present then we turn on that ith bit in maxval so that we can get maximised value.
                    if(node->containskey(!bit)){
                        maxval=maxval | (1<<i);
                        node=node->get(!bit);//after we turn on the ith bit for maxval, we move to that opp. bit reference node of the Trie.
                    }
                    else{
                        node=node->get(bit);//if the opp bit is not present then we already have 0 for that pos. bit so we move on to that reference for further operations.
                    }
                }
                
                return maxval;
            }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *obj=new Trie();
        int maxi=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            obj->insert(nums[i]);
        }
        
        for(int i=0;i<nums.size();i++){
                maxi=max(maxi,obj->findMax(nums[i]));//comparing each maximsed val to filter out the maximum number.
            }
        
        return maxi;
    }
};