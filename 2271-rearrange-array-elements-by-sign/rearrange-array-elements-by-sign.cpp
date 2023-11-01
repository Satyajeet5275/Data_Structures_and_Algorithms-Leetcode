class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int eloc=0,oloc=1;
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[eloc]=nums[i];
                eloc+=2;
            }
            else{
                ans[oloc]=nums[i];
                oloc+=2;
            }
        }
        return ans;
    }
};