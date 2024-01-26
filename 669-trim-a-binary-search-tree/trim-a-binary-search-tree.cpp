class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        if(root){
            
            if(root->val < l)
                return trimBST(root->right,l,h);

            if(root->val >h)
                return trimBST(root->left,l,h);

            root->left = trimBST(root->left,l,h);
            root->right = trimBST(root->right,l,h);
        }
        return root;
    }
};