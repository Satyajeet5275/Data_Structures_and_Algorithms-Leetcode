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
    int maxi=0;
    void solve(TreeNode* root,int ans){
        if(!root)  return ;
        if(!root->left && !root->right) {maxi+=(ans*10)+root->val; return;}
        if(root->left!=NULL) solve(root->left,(ans*10)+root->val);
        if(root->right!=NULL) solve(root->right,(ans*10)+root->val);

    }
    int sumNumbers(TreeNode* root) {
        if(!root)  return 0;
        if(!root->left && !root->right) return root->val;
        solve(root->left,root->val);
        solve(root->right,root->val);
        return maxi;
    }
};