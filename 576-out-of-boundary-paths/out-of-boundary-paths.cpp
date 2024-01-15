class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int j,int m,int n,int rem,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=m || j>=n ) return 1;
        if(rem==0) return 0;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        int up=solve(i-1,j,m,n,rem-1,dp);
        int down=solve(i+1,j,m,n,rem-1,dp);
        int left=solve(i,j-1,m,n,rem-1,dp);
        int right=solve(i,j+1,m,n,rem-1,dp);
        
        return dp[i][j][rem]=(((((up+down)%mod)+left)%mod)+right)%mod;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(sr,sc,m,n,maxMove,dp);
    }
};