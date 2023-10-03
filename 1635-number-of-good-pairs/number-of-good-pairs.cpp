class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // map<int,int> mp;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // mp[x]++;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]) ans++;
            }
        }
        // for(pair x:mp){
        //     if(x.second==1) continue;
        //     ans+=x.second;
        // }
        return ans;
    }
};