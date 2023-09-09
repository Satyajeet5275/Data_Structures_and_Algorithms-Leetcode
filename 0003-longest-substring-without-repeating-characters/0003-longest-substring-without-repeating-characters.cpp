class Solution {
public:
    int solve(int i,string& s,int& n,map<char,int>& mp,vector<int> &dp)
    {
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        if(mp[s[i]]>0) return 0;
        mp[s[i]]++;
        return dp[i]=1+solve(i+1,s,n,mp,dp);
    }
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n=s.length();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            vector<int> dp(n+1,-1);
            maxi=max(maxi,solve(i,s,n,mp,dp));
            mp.clear();
        }
        return maxi;
    }
};