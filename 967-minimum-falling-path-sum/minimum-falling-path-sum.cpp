class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& arr,vector<vector<int>>& dp)
    {
        if(row==0)  return arr[row][col];

        if(dp[row][col]!=-1)    return dp[row][col];
        int mini=INT_MAX;
        mini=arr[row][col]+solve(row-1,col,arr,dp);
        if(col>0)   mini=min(mini,arr[row][col]+solve(row-1,col-1,arr,dp));
        if(col<arr.size()-1)  mini=min(mini,arr[row][col]+solve(row-1,col+1,arr,dp));

        return dp[row][col]=mini;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
       
        int n=mat.size();
        if(mat[n-1][n-1]==0) return -1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int maxi=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=min(maxi,solve(n-1,i,mat,dp));
        }
        return maxi;
    }
};