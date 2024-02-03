class Solution {
public:
    int solve(int ind,vector<int>& arr, int k,vector<int>& dp) {
        if(ind>=arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len=0,maxi=INT_MIN;
        long long int maxSum=INT_MIN;
        for(int i=ind;i<min((int)arr.size(),ind+k);i++){
            len++;
            maxi=max(maxi,arr[i]);
            long long int sum=(len*maxi)+solve(i+1,arr,k,dp);
            maxSum=max(maxSum,sum);
        }
        return dp[ind]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {      
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};