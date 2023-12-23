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
    vector<vector<int>> verticalTraversal(TreeNode* mainRoot) {
        if(mainRoot==NULL) return {};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({mainRoot,{0,0}});
        map<int,map<int,vector<int>>> mp;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* root=it.first;
            int line=it.second.first;
            int lvl=it.second.second;

            mp[line][lvl].push_back(root->val);

            if(root->left!=NULL){
                q.push({root->left,{line-1,lvl+1}});
            }
            if(root->right!=NULL) {
                q.push({root->right,{line+1,lvl+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> col;
            for(auto x:it.second){
                sort(x.second.begin(),x.second.end());
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(col);
        } 
        return ans;
    }
};