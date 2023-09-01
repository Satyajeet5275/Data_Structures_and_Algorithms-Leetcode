class Solution {
public:
int solve(int ind,int buy,vector<int>& ar,vector<vector<int>>& dp)
{
    if(ind==ar.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy) return dp[ind][buy]=max(-ar[ind]+solve(ind+1,0,ar,dp),solve(ind+1,1,ar,dp));
    else    return dp[ind][buy]=max(ar[ind]+solve(ind+1,1,ar,dp),solve(ind+1,0,ar,dp));
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};