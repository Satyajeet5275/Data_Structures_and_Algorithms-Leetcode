class Solution {
public:
    int solve(int i,string& s,int& n,map<char,int>& mp)
    {
        if(i==n) return 0;

        if(mp[s[i]]>0) return 0;

        mp[s[i]]++;
        return 1+solve(i+1,s,n,mp);
    }
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n=s.length();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,solve(i,s,n,mp));
            mp.clear();
        }
        return maxi;
    }
};