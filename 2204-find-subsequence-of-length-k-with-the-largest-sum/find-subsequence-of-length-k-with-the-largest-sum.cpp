class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> nums1=nums;
        sort(nums1.rbegin(),nums1.rend());
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<k;i++){
            mp[nums1[i]]++;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(mp[nums[i]]>0){
                    mp[nums[i]]--;
                    ans.push_back(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};