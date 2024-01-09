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
    void giveLeaf(TreeNode* root,vector<int> &arr){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            arr.push_back(root->val);
            return;
        } 
        giveLeaf(root->left,arr);
        giveLeaf(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        giveLeaf(root1,v1);
        giveLeaf(root2,v2);
        for(int i=0;i<max(v1.size(),v2.size());i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};