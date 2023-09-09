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
 void inorder(TreeNode *root,vector<int>& ans)
{
    if(root==NULL)  return;
    
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
class Solution
{
    public:
    int kthSmallest(TreeNode *root, int K)
    {
        //Default calling Method
        vector<int> ans;
        inorder(root,ans);
        return ans[K-1];
    }
    int kthLargest(TreeNode* root, int K) {
        vector<int> ans;
        inorder(root,ans);
        return ans[ans.size()-K];
    }
};


    
