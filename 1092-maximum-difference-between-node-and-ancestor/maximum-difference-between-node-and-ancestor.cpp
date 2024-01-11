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
    int solve(TreeNode* root,int mini,int maxi){
        if(root==NULL) return abs(maxi-mini);
        return max(solve(root->left,min(mini,root->val),max(maxi,root->val)),solve(root->right,min(mini,root->val),max(maxi,root->val)));
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,root->val,root->val);
    }
};