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
    void inOrder(TreeNode* root,vector<int> &bst){
        if(!root) return;
        inOrder(root->left,bst);
        bst.push_back(root->val);
        inOrder(root->right,bst);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        vector<int> bst;
        inOrder(root,bst);
        int s=0,e=bst.size()-1;
        while(s<e){
            if(bst[s]+bst[e]==k) return true;
            if(bst[s]+bst[e]>k) e--;
            else s++;
        }
        return false;
    }
};