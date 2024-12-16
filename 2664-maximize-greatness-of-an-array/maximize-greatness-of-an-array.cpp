class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[j]){
                j++;
                ans++;
            }
            
        }
        return ans;
    }
};