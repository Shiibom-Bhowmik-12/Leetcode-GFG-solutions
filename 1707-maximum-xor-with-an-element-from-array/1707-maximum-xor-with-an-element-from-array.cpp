#include<bits/stdc++.h>
struct Node{
    Node *links[2];
    
    bool iscontainskey(int ind){
        return (links[ind]!=NULL);
    }
    
    void put(int ind,Node *node){
        links[ind]=node;
    }
    
    Node *get(int ind){
        return links[ind];
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
                   int bit=(num>>i)&1;
                   if(!node->iscontainskey(bit)){
                       node->put(bit,new Node());
                   }
                   
                   node=node->get(bit);
               }
           }
    
           int Max_val(int num){
               Node *node=root;
               int maxi=0;
               
               for(int i=31;i>=0;i--){
                   int bit=(num>>i)&1;
                   if(node->iscontainskey(!bit)){
                       maxi=maxi|(1<<i);
                       node=node->get(!bit);
                   }
                   else{
                       node=node->get(bit);
                   }
               }
               
               return maxi;
           } 
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size(),0);
        Trie *obj=new Trie();
        
        sort(nums.begin(),nums.end());
        
        vector<pair<int,pair<int,int>>> offQ;
        int index=0;
        
        for(auto &it:queries){
            offQ.push_back({it[1],{it[0],index++}});
        }
        
        sort(offQ.begin(),offQ.end());
        int i=0;
        int n=nums.size();
        
        for(auto &it:offQ){
            while(i<n and nums[i]<=it.first){
                obj->insert(nums[i]);
                i++;
            }
            
            if(i!=0){
                res[it.second.second]=obj->Max_val(it.second.first);
            }
            else{
                res[it.second.second]=-1;
            }
        }
        
        return res;
    }
};