class NodeData{
    public:
    int minVal,maxVal,sum;
    NodeData(int mini,int maxi,int sum1){
        minVal=mini;
        maxVal=maxi;
        sum=sum1;
    }
};
class Solution {
public:
    int maxi=0;
    NodeData check(TreeNode* root){
        if(!root){
            return NodeData(INT_MAX,INT_MIN,0);
        }
        NodeData left=check(root->left);
        NodeData right=check(root->right);
        if(left.maxVal<root->val && right.minVal>root->val){
            maxi=max(maxi,(left.sum+right.sum+root->val));
            return NodeData(min(left.minVal,root->val),max(right.maxVal,root->val),(left.sum+right.sum+root->val));
        }
        return NodeData(INT_MIN,INT_MAX,max(left.sum,right.sum));
    }
    int maxSumBST(TreeNode* root) {
        int sum=check(root).sum;
        if(sum>0) return maxi;
        return 0;
    }
};