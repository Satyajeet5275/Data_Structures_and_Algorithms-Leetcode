class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int rep,miss,sum=0,tsum=n*(n+1)/2;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(mp[nums[i]]>1){
                sum-=nums[i];
                rep=nums[i];
            }
        }
        miss=tsum-sum;
        return {rep,miss};
    }
};