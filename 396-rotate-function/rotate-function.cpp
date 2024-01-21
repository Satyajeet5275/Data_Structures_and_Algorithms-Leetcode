class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>sum(n,0);
        for(int i=0;i<n;i++){
            sum[0]+=i*nums[i];
        }
        int j=n-1;
        int tot=accumulate(nums.begin(),nums.end(),0);
        int res=sum[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+tot-n*nums[j--];
            res=max(res,sum[i]);
        }
        return res;
    }
};