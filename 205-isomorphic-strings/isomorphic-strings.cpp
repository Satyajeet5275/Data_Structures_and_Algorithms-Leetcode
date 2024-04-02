class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> mp1,mp2;
        map<char,char> mp;
        int n=s.length();
        for(int i=0;i<n;i++) {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i]) return false;
            else mp[s[i]]=t[i];
            if(mp1[s[i]]!=mp2[t[i]]) return false;
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        return true;
    }
};