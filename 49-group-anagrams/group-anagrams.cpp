class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> mp;
        for(auto x:strs){
            map<char,int> tmp;
            for(auto ch:x) tmp[ch]++;
            mp[tmp].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};