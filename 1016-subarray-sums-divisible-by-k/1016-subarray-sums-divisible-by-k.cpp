class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum=0,ans=0;
        mp[0]=1;
        for(auto x:nums){
            sum=(sum+x)%k;
            if(sum<0) sum+=k;
            if(mp[sum]>=1) ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};


// [4,5,0,-2,-3,1]

// 4 4 4 2 3 4

// ans=7