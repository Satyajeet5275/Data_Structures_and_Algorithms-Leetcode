class Solution {
public:
    int ans=0;
    int dp[1000000];
    long long fun(int ind,vector<int>&v) {
        if(ind<=1) return dp[ind]=v[ind];
        if(dp[ind]!=-1) return dp[ind];
        long long ntake=fun(ind-2,v);
        long long  take=fun(ind-1,v);
        return dp[ind]=v[ind]+min(take,ntake);
    }
    int minCostClimbingStairs(vector<int>&v) {
      int n=v.size();
      memset(dp,-1,sizeof(dp));
       return min(fun(n-1,v),fun(n-2,v));
    }
};