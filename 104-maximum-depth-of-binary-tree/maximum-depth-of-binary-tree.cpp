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
    int findDepth(TreeNode* root,int lvl){
        if(root==NULL) return 0;
        int maxi=lvl;
        if(root->left) maxi=findDepth(root->left,lvl+1);
        if(root->right) maxi=max(maxi,findDepth(root->right,lvl+1)); 
        return maxi;
    }
    int maxDepth(TreeNode* root) {
        int maxi=findDepth(root,1);
        return maxi;
    }
};