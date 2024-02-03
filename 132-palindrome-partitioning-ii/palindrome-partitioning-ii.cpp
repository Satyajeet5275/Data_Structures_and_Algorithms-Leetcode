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
    int solve(int ind,string& s, vector<int> &dp){
        if(ind>=s.length()) return 0;
        if(dp[ind] != -1)
            return dp[ind];

        int cuts=INT_MAX;
        for(int j=s.length()-1;j>=ind;j--){
            if(isPalin(ind,j,s)){
                cuts=min(cuts,1+solve(j+1,s,dp));
            }
        }
        return dp[ind] = cuts;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0,s, dp)-1;
    }
};