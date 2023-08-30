class Solution {
public:
int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
{
    if(i==s1.length() || j==s2.length()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=1+solve(i+1,j+1,s1,s2,dp);
    
    return dp[i][j]=max(solve(i,j+1,s1,s2,dp),solve(i+1,j,s1,s2,dp));
}
    int minDistance(string w1, string w2) {
        int n1=w1.size();
        int n2=w2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int commonChars=solve(0,0,w1,w2,dp);
        return (n1-commonChars)+(n2-commonChars);
    }
};