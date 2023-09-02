class Solution {
public:
int solve(int ind,int buy,int cap,vector<int>& arr,vector<vector<vector<int>>>& dp)
{
    if(ind==arr.size() || cap<=0) return 0;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    if(buy) return dp[ind][buy][cap]=max(-arr[ind]+solve(ind+1,0,cap,arr,dp),solve(ind+1,1,cap,arr,dp));
    else return dp[ind][buy][cap]=max(+arr[ind]+solve(ind+1,1,cap-1,arr,dp),solve(ind+1,0,cap,arr,dp));

}
    int maxProfit(vector<int>& prices) {
       vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1))) ;
       return solve(0,1,2,prices,dp); 
    }
};