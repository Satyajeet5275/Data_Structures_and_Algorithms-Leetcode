class Solution {
public:
    int firstUniqChar(string s) {
        map<char,pair<int,int>> mp;
        for(int i=0;i<s.length();i++) {
            char ch=s[i];
            mp[ch].first++;
            if(mp[ch].first==1) mp[ch].second=i;
        }
        int mini=INT_MAX;
        for(auto x:mp){
            if(x.second.first==1) mini=min(x.second.second,mini); 
        }
        return (mini==INT_MAX)? -1 : mini;
    }
};