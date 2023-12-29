class Solution {
public:
    int solve(int i,int days,vector<int>& jd,vector<vector<int>> & dp){
        if(i>=jd.size() || days<0 ){
            if(days==0) return 0;
            return 1e5;
        }
        if(dp[i][days]!=-1) return dp[i][days];
        int mini=1e4,pick=0,lmax=INT_MIN;
        for(int j=i;j<jd.size();j++){
            lmax=max(lmax,jd[j]);
            pick=lmax+solve(j+1,days-1,jd,dp);
            mini=min(mini,pick);
        }
        return dp[i][days]=mini;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return solve(0,d,jd,dp);
    }
};