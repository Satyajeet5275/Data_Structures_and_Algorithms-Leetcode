class Solution {
public:
    bool solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
    {
            if(i<0 && j<0) return true;
            else if(j<0 && i>=0) return false;
            if(i<0 && j>=0){
                for(int x=0;x<=j;x++)   if(s2[x]!='*') return false;
                return true;
            }
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j] || s2[j]=='?') return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
        if(s2[j]=='*') return dp[i][j]=( solve(i-1,j,s1,s2,dp) || solve(i,j-1,s1,s2,dp) );
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,s,p,dp);
    }
};