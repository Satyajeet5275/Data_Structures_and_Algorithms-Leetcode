class Solution {
public:
int solve(int i,int prev_i,vector<int>& arr,int n,vector<vector<int>>& dp)
{
    if(i==n) return 0;
    if(dp[i][prev_i+1]!=-1) return dp[i][prev_i+1];
    int len=0+solve(i+1,prev_i,arr,n,dp);
    if(prev_i==-1 || arr[i]>arr[prev_i]) len=max(len,1+solve(i+1,i,arr,n,dp));

    return dp[i][prev_i+1]=len;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(0,-1,nums,nums.size(),dp);
    }
};