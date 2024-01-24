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
    bool isPalindrome(map<int,int>& mp,int& n){
        if(n%2==0){
            for(auto x:mp){
                if(x.second%2!=0) return false; 
            }
            return true;
        }
        else{
            int odd=0;
            for(auto x:mp){
                if(x.second%2!=0) odd++; 
                if(odd>1) return false;
            }
            return true;
        }
    }
    int solve(TreeNode* root,map<int,int>& mp,int n){
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            n++;
            if(isPalindrome(mp,n)){ 
                mp[root->val]--;
                return 1;
            }
            mp[root->val]--;
            return 0;
        }
        mp[root->val]++;
        n++;
        int l=0,r=0;
        if(root->left) l=solve(root->left,mp,n);
        if(root->right) r=solve(root->right,mp,n);
        mp[root->val]--;
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        return solve(root,mp,0);
    }
};