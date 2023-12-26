class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int target,int &n,int &k,vector<vector<int>> &dp){
        if(i==n && target==0)  return 1;
        if(i>=n) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int pick=0;
        for(int j=1;j<=k;j++){
            if(target>=j) pick=(pick+solve(i+1,target-j,n,k,dp))%mod; 
        }
        return dp[i][target]=pick;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target,n,k,dp);
    }
};