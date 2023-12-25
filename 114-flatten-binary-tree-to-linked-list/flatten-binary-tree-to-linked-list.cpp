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
    // TreeNode* makeFlat(TreeNode* root){
    //     if(root==NULL) return NULL;
    //     TreeNode* node=new TreeNode(root->val);
    //     if(root->left){
    //         node->right=makeFlat(root->left);
    //     }
    //     else if(root->right){
    //         node->right=makeFlat(root->right);
    //     }
    //     return node;
    // }
    TreeNode * prev=NULL;
    void flatten(TreeNode* root) {        
       if(root==NULL) return;

       flatten(root->right);
       flatten(root->left);

       root->right=prev;
       root->left=NULL;
       prev=root;
    }
};