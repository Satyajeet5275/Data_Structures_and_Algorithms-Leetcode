class Solution {
public:
    static bool compair(pair<int,string> p1,pair<int,string> p2){
        if(p1.first==p2.first) return p1.second<p2.second;
        return p1.first>p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto x:words){
            mp[x]++;
        }
        vector<pair<int,string>> ans;
        for(auto i:mp){
            ans.push_back({i.second,i.first});
        }
        sort(ans.begin(),ans.end(),compair);
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(ans[i].second);
        }
        return res;
    }
};