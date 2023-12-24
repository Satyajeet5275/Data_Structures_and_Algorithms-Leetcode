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
    int height(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int lval=max(0,height(root->left,maxi));
        int rval=max(0,height(root->right,maxi));
        maxi=max(maxi,lval+rval+root->val);

        return root->val+max(lval,rval);
    }
    int maxPathSum(TreeNode* root) {
       int maxi=-1e5;
       height(root,maxi);
       return maxi;
    }
};