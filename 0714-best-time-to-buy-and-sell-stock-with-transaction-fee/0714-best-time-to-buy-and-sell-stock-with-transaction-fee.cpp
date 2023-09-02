class Solution {
public:
  int solve(int ind,int buy,vector<int>& arr,vector<vector<int>>& dp,int fee)
{
    if(ind>=arr.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy) return dp[ind][buy]=max(-arr[ind]+solve(ind+1,0,arr,dp,fee),solve(ind+1,1,arr,dp,fee));
    else return dp[ind][buy]=max(+arr[ind]+solve(ind+1,1,arr,dp,fee)-fee,solve(ind+1,0,arr,dp,fee));
}
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1)) ;
        return solve(0,1,prices,dp,fee);
    }
};