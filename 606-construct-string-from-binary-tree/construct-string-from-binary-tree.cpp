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
    void preOrder(string &s,TreeNode* root){
        if(root==NULL) return;

        s+=to_string(root->val);
        if(root->left!=NULL){
            s+="(";
            preOrder(s,root->left);
            s+=")";
        }
        if(root->right!=NULL){
            if(root->left==NULL) s+="()";
            s+="(";
            preOrder(s,root->right);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string s="";
        preOrder(s,root);
        return s;
    }
};