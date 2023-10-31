class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int ind=0,mini=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=mini && nums[i-1]>nums[i] ){
                ind=i;
                mini=nums[i];
            }
            // if(i==n-1 && nums[i]<=mini && nums[i-1]>nums[i]) ind=i;
        }
        cout<<ind;
        for(int i=ind;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        if(ind>0 && nums[n-1]>nums[0]) return false;
        for(int i=0;i<ind-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
};