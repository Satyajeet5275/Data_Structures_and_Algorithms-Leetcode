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
int longest=0;
int preOrder(TreeNode *root,int lvl,map<int,long long>& ans)
{
    if(root==NULL)  return max(longest,lvl);
    
    ans[lvl]+=root->val;
    int a=preOrder(root->left,lvl+1,ans);
    int b=preOrder(root->right,lvl+1,ans);
    return max(a,b);
}
   
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int,long long> ans;
        int levels=preOrder(root,0,ans);
        cout<<levels;
        if(levels<k) return -1;

        vector<long long> sums;
        for(auto x:ans) sums.push_back(x.second);
        sort(sums.rbegin(),sums.rend());
        return sums[k-1];
    }
};