class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<n-1 && nums[left+1]>nums[left]) left++;
        while(right>0 && nums[right-1]<nums[right]) right--;

        int ans=(left==n-1) ? 0 : (n-right)+1;
        for(int i=0;i<=left;i++){
            int index= upper_bound(nums.begin()+right,nums.end(),nums[i])-nums.begin();
            ans+=(n-index)+1;
        }
        return ans;
    }
};