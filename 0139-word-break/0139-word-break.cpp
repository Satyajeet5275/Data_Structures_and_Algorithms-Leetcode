class Solution {
public:

bool solve(int i,string& s, set<string>& wd,vector<int>& dp) {
    if(i>=s.size()) return true;
    if(dp[i]!=-1)   return dp[i];
    string t="";
    for(int x=i;x<s.size();++x)
    {
        t+=s[x];
        if(wd.find(t)!=wd.end() && solve(x+1,s,wd,dp))
        {
            dp[i]=1;
            return true;
        }
            
    }
    dp[i]=0;
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wd(wordDict.begin(),wordDict.end());
        vector<int> dp(301,-1);
        return solve(0,s,wd,dp);
        
    }
};