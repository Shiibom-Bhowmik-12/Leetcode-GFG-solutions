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
    
    void helper(TreeNode *root,vector<vector<int>> &v,vector<int> res,int sum,int target){
        if(isleaf(root) and sum==target){
            res.push_back(root->val);
            v.emplace_back(res);
            return;
        }
        
        res.push_back(root->val);
        if(root->left){
            // res.push_back(root->left->val);
            //sum+=root->left->val;
            helper(root->left,v,res,sum+root->left->val,target);
        }
        
        if(root->right){
            // res.push_back(root->right->val);
            //sum+=root->right->val;
            helper(root->right,v,res,sum+root->right->val,target);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        
        vector<int> res;
        helper(root,v,res,root->val,targetSum);
        return v;
    }
};