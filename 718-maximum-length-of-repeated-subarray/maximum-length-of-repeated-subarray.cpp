class Solution {
public:
    int ans;
    int solve(int i, int j, vector<int>& arr1, vector<int>& arr2,vector<vector<int>> &dp) {
        if (i >= arr1.size() || j >= arr2.size())
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick = 0;
        if (arr1[i] == arr2[j]) {
            pick=1+solve(i+1,j+1,arr1,arr2,dp);
            ans=max(ans,pick);
        }      
        solve(i+1,j,arr1,arr2,dp);
        solve(i,j+1,arr1,arr2,dp);
        
        return dp[i][j]=pick;
    }
    int findLength(vector<int>& arr1, vector<int>& arr2) {
        vector<vector<int>> dp(arr1.size(),vector<int>(arr2.size(),-1));
        solve(0, 0, arr1, arr2,dp);
        return ans;
    }
};