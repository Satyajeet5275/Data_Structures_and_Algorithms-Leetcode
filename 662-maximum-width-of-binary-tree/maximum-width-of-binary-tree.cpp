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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second;
            int start,end;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                long long nodeId=it.second-mini;
                TreeNode *node=it.first;
                if(i==0) start = nodeId;
                else if(i==n-1) end = nodeId;
                
                cout<<nodeId<<endl;
                
                if(node->left!=NULL) {
                    q.push({node->left,nodeId*2+1});
                }
                if(node->right!=NULL) {
                    q.push({node->right,nodeId*2+2});
                }
            }
            ans=max(ans,(end-start+1));
        }
        return ans;
    }
};