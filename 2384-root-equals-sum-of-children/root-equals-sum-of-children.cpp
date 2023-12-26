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
    bool checkTree(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        bool left=checkTree(root->left);
        bool right=checkTree(root->right);

        if(left && right && (root->left && root->right) && (root->val == root->right->val+root->left->val)) return true;
        else if(left && right && (root->left && !root->right) && (root->val == root->left->val)) return true;
        else if(left && right && (root->right && !root->left) &&(root->val == root->right->val)) return true;
        return false;
    }
};