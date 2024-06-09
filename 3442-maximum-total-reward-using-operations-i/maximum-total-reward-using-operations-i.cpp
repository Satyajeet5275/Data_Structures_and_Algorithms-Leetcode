class Solution {
public:
    int solve(int ind,int rew,int& n,vector<int>& arr,vector<vector<int>>& dp){
        if(ind==n) return rew;
        int maxi=0;
        if(dp[ind][rew]!=-1) return dp[ind][rew];
        // for(int i=ind+1;i<n;i++){
        //     if(arr[i]>rew){
        //         int curr=solve(i,rew+arr[i],n,arr,dp);
        //         maxi=max(curr,maxi);
        //     }
        // }
        int nonpick=solve(ind+1,rew,n,arr,dp);
        int pick=0;
        
        if(rew<arr[ind]){
            pick=solve(ind+1,rew+arr[ind],n,arr,dp);
        }
        maxi=max(pick,nonpick);
        return dp[ind][rew]=maxi;
    }
    int maxTotalReward(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(2001,vector<int>(4000,-1));
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,n,arr,dp));
        }
        return ans;
    }
};