class Solution {
public:
    int mod=1e9+7;
    int solve(int start,int currDay,int& n,int& delay,int& forget,vector<vector<int>>& dp){
        if(currDay>n) return 1;
        if((currDay-start)==forget) return 0;

        if(dp[start][currDay]!=-1) return dp[start][currDay];

        long long int ans=0;
        if((currDay-start)<delay){
            ans=solve(start,currDay+1,n,delay,forget,dp);
        }
        else{
            ans=(solve(currDay,currDay+1,n,delay,forget,dp)+solve(start,currDay+1,n,delay,forget,dp))%mod;
        }
        return dp[start][currDay]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,1,n,delay,forget,dp);
    }
};