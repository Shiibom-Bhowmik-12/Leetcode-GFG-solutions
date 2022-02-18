/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parents(TreeNode *root,TreeNode *target,unordered_map<TreeNode *,TreeNode *> &parents){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left){
                parents[curr->left]=curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                parents[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        
        unordered_map<TreeNode *,TreeNode *> parents;
        mark_parents(root,target,parents);
        
        unordered_map<TreeNode *,bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target]=true;
        int count=0;
        
        while(!q.empty()){
            int size=q.size();
            if(count++ == k){
                    break;
            }
                
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                q.pop();
                
                if(curr->left and !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                
                if(curr->right and !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                
                if(parents[curr] and !visited[parents[curr]]){
                    q.push(parents[curr]);
                    visited[parents[curr]]=true;
                }
            }
        }
        
        while(!q.empty()){
            v.emplace_back(q.front()->val);
            q.pop();
        }
        
        return v;
    }
};