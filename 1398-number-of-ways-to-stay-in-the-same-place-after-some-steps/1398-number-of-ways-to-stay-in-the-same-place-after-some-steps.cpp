class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,int step,int arrLen,vector<vector<int>>& dp){
        if(step==0){
            if(ind==0) return 1;
            return 0;
        }
        if(dp[step][ind]!=-1) return dp[step][ind];

        int stay=solve(ind,step-1,arrLen,dp);
        int right=0,left=0;
        if(ind>0) left=solve(ind-1,step-1,arrLen,dp);
        if(ind<(arrLen-1)) right=solve(ind+1,step-1,arrLen,dp);
        return dp[step][ind]=((((stay+right)%mod)+left)%mod);
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1,vector<int>(steps+1,-1));
        return solve(0,steps,arrLen,dp);
    }
};