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
    void count(TreeNode *root,int &c,int maxi){
        if(root==NULL){
            return;
        }
        
        if(root->val >= maxi){
            c++;
            maxi=root->val;
        }
        
        count(root->left,c,maxi);
        count(root->right,c,maxi);
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        if(!root->left and !root->right){
            return 1;
        }
        
        int c=0;
        count(root,c,INT_MIN);
        return c;
    }
};