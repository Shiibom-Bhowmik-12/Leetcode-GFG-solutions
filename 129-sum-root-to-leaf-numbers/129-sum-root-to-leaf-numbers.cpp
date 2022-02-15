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
    bool isleaf(TreeNode *root){
        return (root->left==NULL and root->right==NULL);
    }
    
    void helper(TreeNode* root,vector<int> &v,int sum){
        if(isleaf(root)){
            v.push_back(sum);
            return;
        }
        
        if(root->left){
            helper(root->left,v,sum*10+root->left->val);
        }
        
        if(root->right){
            helper(root->right,v,sum*10+root->right->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        vector<int> v;
        helper(root,v,root->val);
        
        int res=0;
        for(auto x:v){
            res+=x;
        }
        
        return res;
    }
};