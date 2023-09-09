class Solution {
public:
int solve(int ind,int sum,int& target,vector<int>& nums,vector<vector<int>>& dp)
{
    if(sum==target) return 1;
    if(ind>=nums.size())
    {
     return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int count=0;
    for(int x=0;x<nums.size();x++)
    {
        if(sum+nums[x]<=target)
        {
            count+=solve(x,sum+nums[x],target,nums,dp);
        }
    }
    return dp[ind][sum]=count;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,0,target,nums,dp);
    }
};