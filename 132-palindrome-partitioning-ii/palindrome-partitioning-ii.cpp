class Solution {
public:
    bool isPalin(int i, int j,string& s){
        while(i<j){
            if(s[i]!=s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    int solve(int i,int n, string& s ,  vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];

        int ans = INT_MAX, mn = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalin(i,j,s)){
                ans = min(ans, 1 + solve(j+1,n,s,dp));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp)-1;
    }
};