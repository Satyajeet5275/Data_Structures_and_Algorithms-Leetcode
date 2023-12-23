/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    void morrisPreOrder(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        morrisPreOrder(root, ans);
        return ans;
    }
};