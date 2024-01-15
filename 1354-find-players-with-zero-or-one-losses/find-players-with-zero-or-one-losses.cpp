class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int> mp;
        int n=mat.size();

        for(int i=0;i<n;i++){
            int win=mat[i][0];
            int loose=mat[i][1];
            mp[loose]++;
            if(mp[win]>0) continue;
            mp[win]=0; 
        }
        vector<int> win,lost;
        for(auto x:mp){
            if(x.second==0) win.push_back(x.first);
            if(x.second==1) lost.push_back(x.first);
        }
        return {win,lost};
    }
};