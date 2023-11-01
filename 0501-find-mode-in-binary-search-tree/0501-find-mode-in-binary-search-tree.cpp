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
map<int,int> mp;
int maxi=INT_MIN;
void preOrder(TreeNode* root){
    if(root==NULL) return;
    mp[root->val]++;
    maxi=max(maxi,mp[root->val]);
    preOrder(root->left);
    preOrder(root->right);
}
    vector<int> findMode(TreeNode* root) {
        preOrder(root);
        vector<int> ans;
        for(pair it:mp){
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
    }
};