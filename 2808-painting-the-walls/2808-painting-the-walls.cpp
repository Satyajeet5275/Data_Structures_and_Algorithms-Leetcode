class Solution {
public:
    int solve(int ind,int rem,int n,vector<int>& cost, vector<int>& time,vector<vector<int>>& dp){
        if(rem <= 0) return 0;
        if(ind>=n) return 1e9;
        if(dp[ind][rem]!=-1) return dp[ind][rem];

        int np=solve(ind+1,rem,n,cost,time,dp);
        int p=1e5;
        p=cost[ind]+ solve(ind+1,rem-time[ind]-1,n,cost,time,dp);
        return dp[ind][rem]= min(np,p);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(501,vector<int>(n+1,-1)));
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,n,n,cost,time,dp);
    }
};
// class Solution {
// public:
//     int solve(vector<int>& cost, vector<int>& time, int i, int bank,vector<vector<int>> &dp){
//         if(bank <= 0){
//             return 0;
//         }
//         if(i >= cost.size()){
//             return 1e9;   
//         }
//         if(dp[i][bank] != -1){
//             return dp[i][bank];
//         }
//         else {
//             int notTake = solve(cost, time, i+1, bank,dp);
//             int take = cost[i] + solve(cost, time, i+1, bank -  time[i] -1,dp); 
//             return dp[i][bank] = min(notTake, take);      
//         }
//     }

//     int paintWalls(vector<int>& cost, vector<int>& time) {
//         vector<vector<int>> dp(501,vector<int>(501,-1));
//         return solve(cost, time, 0, time.size(),dp);
//     }
// };