class Solution {
public:
    int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
    {
        //base case 
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return 1+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=max(solve(i,j-1,s1,s2,dp),solve(i-1,j,s1,s2,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.size(),n2=t2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,t1,t2,dp);
    }
};