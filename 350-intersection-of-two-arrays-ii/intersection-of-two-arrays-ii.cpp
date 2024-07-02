class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,pair<int,int>> mp;
        for(auto x:nums1){
            mp[x].first++;
        }
        for(auto x:nums2){
            mp[x].second++;
        }
        vector<int> ans;
        for(auto x:mp){
            int occ1=x.second.first;
            int occ2=x.second.second;
            int res=min(occ1,occ2);
            while(res--){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};