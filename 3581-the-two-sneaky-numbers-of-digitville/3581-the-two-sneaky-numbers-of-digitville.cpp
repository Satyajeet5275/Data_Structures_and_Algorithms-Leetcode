class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;
        for(auto x:nums){
            mp[x]++;
            if(mp[x]>1) ans.push_back(x);
        }
        return ans;
    }
};