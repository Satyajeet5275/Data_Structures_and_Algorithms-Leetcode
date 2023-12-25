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
    TreeNode* build(vector<int>& bst,int bstart,int bend,vector<int>& pre,int pstart,int pend,map<int,int> &mp){
        if(pstart>pend || bstart>bend) return NULL;

        TreeNode* root=new TreeNode(pre[pstart]);
        int inRoot=mp[pre[pstart]];
        int remLeft=inRoot-bstart;
        root->left=build(bst,bstart,inRoot-1,pre,pstart+1,pstart+remLeft,mp);
        root->right=build(bst,inRoot+1,bend,pre,pstart+1+remLeft,pend,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> bst=pre;
        sort(bst.begin(),bst.end());
        map<int,int> mp;
        for(int i=0;i<pre.size();i++) {
             mp[bst[i]]=i;
        }
        return build(bst,0,bst.size()-1,pre,0,pre.size()-1,mp);
    }
};

// [ 1,5,7,8,10,12 ] -> bst
// [ 8,5,1,7,10,12 ] -> pre