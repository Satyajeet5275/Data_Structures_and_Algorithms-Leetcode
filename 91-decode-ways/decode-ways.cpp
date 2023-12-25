class Solution {
public:
    int solve(int i,string &s,vector<int> &dp){
        if(i==s.length()) return 1;
        if(i>s.length()) return 0;
        if(dp[i]!=-1) return dp[i];

        int nonPick=0,pick=0;
        if(i<s.length()-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<=54) && s[i+2]!='0')
            nonPick=solve(i+2,s,dp);

        if(s[i+1]!='0')
            pick=solve(i+1,s,dp);

        return dp[i]=(pick+nonPick);
    }
    int numDecodings(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'&& (i==0 || (s[i-1]>50 || s[i-1]<=48)))  return 0;
        }
        vector<int> dp(s.length()+1,-1);
        int ways=solve(0,s,dp);
        return ways;
    }
};