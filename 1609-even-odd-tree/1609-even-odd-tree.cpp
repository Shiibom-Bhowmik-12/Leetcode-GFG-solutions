/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEven(vector<int> v){
       if(v[0]%2==0){
           return false;
       }
    
       for(int i=1;i<v.size();i++){
           if(v[i]%2==0 or v[i-1]>=v[i]){
               return false;
           }
       }
       
       return true;
    }
    
    bool checkOdd(vector<int> v){
        if(v[0]%2!=0){
            return false;
        }
        
        for(int i=1;i<v.size();i++){
            if(v[i]%2!=0 or v[i-1]<=v[i]){
                return false;
            }
        }
        
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int level=0;
        bool flag=true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int> v;
            
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                q.pop();
                v.emplace_back(curr->val);
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
            if(level%2==0){
                flag=checkEven(v);
            }
            else{
                flag=checkOdd(v);
            }
            
            if(flag==false){
                return false;
            }
            
            v.clear();
            level++;
        }
        
        return flag;
    }
};