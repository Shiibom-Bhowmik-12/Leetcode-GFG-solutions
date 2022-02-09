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
    void helper_1(TreeNode *root1,multiset<int> &s){
       if(root1==NULL){
           return; 
       } 
        
       helper_1(root1->left,s);
       s.insert(root1->val);
       helper_1(root1->right,s);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        multiset<int> s;
        helper_1(root1,s);
        helper_1(root2,s);
        
        for(auto x:s){
            v.emplace_back(x);
        }
        return v;
    }     
};