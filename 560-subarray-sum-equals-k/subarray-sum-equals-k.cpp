class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum=0,ans=0;
        for(auto x:nums){
            sum+=x;
            if(sum==k) ans++;
            if(mp[sum-k]>=1) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};

// [1,2,-2,3]

// 1  3  1  4

// pref[i]-k = 

// ans=1