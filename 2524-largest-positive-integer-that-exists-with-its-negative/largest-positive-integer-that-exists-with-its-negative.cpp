class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums) {
            mp[x]++;
        }
        int maxi=-1;
        for(auto x:mp){
            int n=x.first;
            if(n>0 && mp[-1*n]>=1){
                maxi=max(maxi,n);
            }
        }
        return maxi;
    }
};