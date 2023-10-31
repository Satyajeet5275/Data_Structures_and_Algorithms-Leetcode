class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int h = 1;
        vector<int> ans;
        while(l < nums.size()){
            while(h < nums.size()){
                if(nums[l] + nums[h] == target){
                    ans.push_back(l);
                    ans.push_back(h);
                }
                h++;
            }     
            l++;
            h = l + 1;
        }
        return ans;
    }
};