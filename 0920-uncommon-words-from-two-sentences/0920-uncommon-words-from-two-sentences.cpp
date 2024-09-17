class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1),ss2(s2);   string word;   map<string,int> mp;  while(getline(ss1,word,' '))    mp[word]++;        while(getline(ss2,word,' '))    mp[word]++;        vector<string> ans;for(auto x:mp)   if(x.second==1) ans.push_back(x.first); return ans;
    }
};