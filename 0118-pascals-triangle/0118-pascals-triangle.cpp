class Solution {
public:
int dp[31][31];
int nCr(int n, int r) {
    // Base cases
    if (r == 0 || r == n) 
        return 1;
    if(dp[n][r]!=-1)
    return dp[n][r];
        // Recursively calculate nCr using the formula
    return dp[n][r]=nCr(n - 1, r - 1) + nCr(n - 1, r);
}
    vector<vector<int>> generate(int numRows) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>v;
        for(int n=0;n<numRows;n++){
            vector<int>v1;
         for(int r=0;r<=n;r++){
           v1.push_back(nCr(n,r));
         }
         v.push_back(v1);
        }
        return v;
    }
};