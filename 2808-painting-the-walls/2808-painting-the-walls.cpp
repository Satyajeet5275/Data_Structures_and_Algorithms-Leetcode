class Solution {
public:
    int solve(int ind,int rem,int n,vector<int>& cost, vector<int>& time,vector<vector<int>>& dp){
        if(rem <= 0) return 0;
        if(ind>=n) return 1e9;
        if(dp[ind][rem]!=-1) return dp[ind][rem];

        int np=solve(ind+1,rem,n,cost,time,dp);
        int p=cost[ind]+ solve(ind+1,rem-time[ind]-1,n,cost,time,dp);
        return dp[ind][rem]= min(np,p);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,n,n,cost,time,dp);
    }
};