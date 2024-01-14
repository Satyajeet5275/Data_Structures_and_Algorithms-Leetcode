class Solution {
public:
    static bool check(vector<int>& v1,vector<int>& v2){
        if(v1[0]==v2[0]){
            return !(v1[1]<v2[1]);
        }
        return (v1[0]<v2[0]);
    }
    // int solve(int ind,int prev,int n,vector<vector<int>>& env,vector<vector<int>>& dp){
    //     if(ind==n) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int pick=0,nonpick=0;
    //     nonpick=solve(ind+1,prev,n,env,dp);
    //     if(prev==-1 || env[ind][1]>env[prev][1]) pick=1+solve(ind+1,ind,n,env,dp);
    //     return dp[ind][prev+1]=max(pick,nonpick);
    // }
    int binarySearch(vector<vector<int>>& env,int n){
        if(n==0) return 0;
        vector<int> ans;
        ans.push_back(env[0][1]);
        for(int i=1;i<n;i++){
            if(env[i][1]>ans.back()) ans.push_back(env[i][1]);
            else{
                int loc=lower_bound(ans.begin(),ans.end(),env[i][1])-ans.begin();
                ans[loc]=env[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),check);
        int n=env.size();
        // vector<vector<int>> dp(env.size()+1,vector<int>(env.size()+1,-1));
        // return solve(0,-1,env.size(),env,dp);
        return binarySearch(env,n);
    }
};