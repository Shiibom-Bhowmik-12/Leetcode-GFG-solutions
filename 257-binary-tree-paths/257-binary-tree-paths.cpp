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
    
    void helper(TreeNode *root,vector<string> &v,string s){
        if(isleaf(root)){
            v.emplace_back(s);
            return;
        }
        
        if(root->left){
            helper(root->left,v,s+"->"+to_string(root->left->val));
        }
        
        if(root->right){
            helper(root->right,v,s+"->"+to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root==NULL){
            return v;
        }
        
        helper(root,v,to_string(root->val));
        return v;
    }
};