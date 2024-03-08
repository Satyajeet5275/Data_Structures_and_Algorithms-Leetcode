class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=0,freq=0;
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
            maxi=max(maxi,mp[x]);
        }
        for(auto x:mp){
            if(x.second==maxi) freq++;
        }
        return maxi*freq;
    }
};