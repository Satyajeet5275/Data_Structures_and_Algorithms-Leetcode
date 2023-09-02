class Solution {
public:
int solve(int ind,int buy,vector<int>& arr,vector<vector<int>>& dp)
{
    if(ind>=arr.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy) return dp[ind][buy]=max(-arr[ind]+solve(ind+1,0,arr,dp),solve(ind+1,1,arr,dp));
    else return dp[ind][buy]=max(+arr[ind]+solve(ind+2,1,arr,dp),solve(ind+1,0,arr,dp));
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1)) ;
        return solve(0,1,prices,dp);
    }
};