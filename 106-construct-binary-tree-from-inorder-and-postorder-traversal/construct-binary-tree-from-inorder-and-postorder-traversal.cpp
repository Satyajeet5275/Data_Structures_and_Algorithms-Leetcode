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
    TreeNode* buildNode(vector<int>& post,int postStart,int postEnd,vector<int>& in,int inStart,int inEnd,map<int,int>& mp) {
        if(postStart>postEnd || inStart>inEnd) return NULL;
        
        TreeNode *root= new TreeNode(post[postEnd]);
        int inRoot=mp[post[postEnd]];
        int numLeft=inRoot-inStart;
        
        root->left=buildNode(post,postStart,postStart+numLeft-1,in,inStart,inRoot-1,mp);
        root->right=buildNode(post,postStart+numLeft,postEnd-1,in,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode* root = buildNode(post,0,post.size()-1,in,0,in.size()-1,mp);
        return root;
    }
};