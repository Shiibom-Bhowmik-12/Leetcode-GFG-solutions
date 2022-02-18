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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        int ans=INT_MIN;
        
        while(!q.empty())
        {
            int size=q.size();
            int mini=q.front().second;
            int last=0,first=0;
            
            for(int i=0;i<size;i++)
            {
                TreeNode *k=q.front().first;
                int curr=q.front().second-mini;
                q.pop();
                
                if(i==0){
                    first=curr;
                }
                
                if(i==size-1){
                    last=curr;
                }
                
                if(k->left){
                    q.push({k->left,curr*2+1});
                }
                
                if(k->right){
                    q.push({k->right,curr*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        
        return ans;
    }
};