// Memoization (Tle at 144)
// class Solution {
// public:
//     long long solve(int r, int c, int n,int m,vector<vector<int>>& arr,vector<vector<long long>>& dp) {
//         if(r>=n || c>=m) return 0;

//         if(dp[r][c]!=-1) return dp[r][c];

//         long long score=0;
//         for(int i=0;i<m;i++){
//             long long curr=solve(r+1,i,n,m,arr,dp)-abs(c-i);
//             score=max(score,curr);
//         }
//         return  dp[r][c]=score+arr[r][c];
//     }
//     long long maxPoints(vector<vector<int>>& arr) {
//         int n = arr.size(), m = arr[0].size();
//         vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
//         long long maxi=0;
//         for (int i=0;i<m;i++){
//             maxi=max(maxi,solve(0, i, n, m, arr, dp));
//         }
//         return maxi;
//     }
// };

class Solution
{
public:
    typedef long long ll;
    int n, m;

    long long maxPoints(vector<vector<int>> &points)
    {
        n = points.size();
        m = points[0].size();

        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

        // Filling the top row as we have no prev row to it (base case)
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = points[0][i]; 
        }

        //For every row after 0th we traverse from both sides and take maximum
        for (int i = 1; i < n; i++)
        {
            // Find max value till that column from left and right
            vector<ll> leftMax(m), rightMax(m);

            //Filling leftMax table
            leftMax[0] = dp[i - 1][0];
            for (int j = 1; j < m; j++)
            {
                leftMax[j] = max(leftMax[j - 1] - 1, dp[i - 1][j]);
            }

            //Filling rightMax table
            rightMax[m - 1] = dp[i - 1][m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                rightMax[j] = max(rightMax[j + 1] - 1, dp[i - 1][j]);
            }

            // In the end we find the max value for every col in that ith row
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }


        // The answer will be the max value in the last row.
        ll ans = 0;
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[n - 1][j]);
        }

        return ans;
    }
};