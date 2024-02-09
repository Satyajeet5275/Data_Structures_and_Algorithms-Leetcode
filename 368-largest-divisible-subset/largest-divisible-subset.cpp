class Solution {
public:

    void solve(int ind,vector<int>& nums,vector<int> curr,vector<int>& dp,vector<int>& ans){
        if(ind>=nums.size()){
            if(curr.size()>ans.size()) ans=curr;
            return ;
        }
        if(curr.size()==0){
            curr.push_back(nums[ind]);
            solve(ind+1,nums,curr,dp,ans);
            curr.pop_back();
        }
        else if((int)curr.size()>dp[ind] && nums[ind]%curr.back()==0){
            dp[ind]=curr.size();
            curr.push_back(nums[ind]);
            solve(ind+1,nums,curr,dp,ans);
            curr.pop_back();
        }
        solve(ind+1,nums,curr,dp,ans);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        vector<int> ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,{},dp,ans);
        return ans;
    }
};