class Solution {
private:
    map<int,int> mp;
    void countSetBits(int n){
        int loc=1;
        while(n>0){
            if(n & 1 == 1) mp[loc]++;
            loc*=2;
            n=n>>1;
        }
    }
public:
    int largestCombination(vector<int>& nums) {
        int maxi=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            countSetBits(nums[i]);
        }
        for(auto x:mp){
            maxi=max(maxi,x.second);
        }
        return maxi;
    }
};