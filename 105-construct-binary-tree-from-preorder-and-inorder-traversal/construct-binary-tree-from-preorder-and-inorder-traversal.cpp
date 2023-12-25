class Solution {
public:
    TreeNode* buildNode(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd,map<int,int>& mp) {
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode *root= new TreeNode(pre[preStart]);
        int inRoot=mp[pre[preStart]];
        int numLeft=inRoot-inStart;
        
        root->left=buildNode(pre,preStart+1,preStart+numLeft,in,inStart,inRoot-1,mp);
        root->right=buildNode(pre,preStart+numLeft+1,preEnd,in,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode* root = buildNode(pre,0,pre.size()-1,in,0,in.size()-1,mp);
        return root;
    }
};