class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp,occ;
        for(auto x:arr){
            mp[x]++;
        }
        for(auto x:mp){
            if(occ[x.second]!=0) return false;
            occ[x.second]++;
        }
        return true;
    }
};