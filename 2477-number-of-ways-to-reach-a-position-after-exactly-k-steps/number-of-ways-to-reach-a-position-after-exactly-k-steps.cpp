class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,int rem,int target, vector<vector<int>>& dp,int k){
        if(rem==0){
            if(ind==target) return 1;
            return 0;
        }
        if(dp[1000+ind][rem]!=-1) return dp[1000+ind][rem];
        int back=solve(ind-1,rem-1,target,dp,k)%mod;
        int forw=solve(ind+1,rem-1,target,dp,k)%mod;
        return dp[1000+ind][rem]=(back+forw)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        return solve(startPos,k,endPos,dp,k);
    }
};