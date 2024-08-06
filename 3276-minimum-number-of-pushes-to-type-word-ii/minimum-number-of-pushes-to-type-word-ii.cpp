class Solution {
public:
    int minimumPushes(string wd) {
                vector<pair<int,char>> v;
        map<char,int> mp; 
        int n=wd.length();
        for(int i=0;i<n;i++){
            mp[wd[i]]++;
        }
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int cost=0;
        
        for(int i=1;i<=v.size();i++){
            int freq=v[i-1].first;
            cost+=freq*(ceil((double)i/(double)8));
        }
        return cost;
    }
};