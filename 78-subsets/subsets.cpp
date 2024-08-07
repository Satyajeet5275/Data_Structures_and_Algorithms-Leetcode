class Solution {
public:
    void solve(vector<int> nums,vector<int> output,vector<vector<int>>& ans,int index)
    {
        //base case
        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        solve(nums,output,ans,index+1);
        output.push_back(nums[index]);
        solve(nums,output,ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,ans,0);

        return ans;
    }
};