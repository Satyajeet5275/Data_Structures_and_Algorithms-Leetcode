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
    int inOrder(TreeNode* root,int& n){
        if(root==NULL) return 0;
        n++;
        int sum=root->val+inOrder(root->left,n)+inOrder(root->right,n);
        return sum;
    }
    int inOrder1(TreeNode* root){
        if(root==NULL) return 0;
        int n=0;
        int avg=inOrder(root,n)/n;
        if(avg==root->val) return 1+inOrder1(root->left)+inOrder1(root->right);
        return (inOrder1(root->left)+inOrder1(root->right));
    }
    int averageOfSubtree(TreeNode* root) {     
        int ans=inOrder1(root);
        return ans;
    }
};