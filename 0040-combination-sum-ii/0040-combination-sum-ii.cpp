class Solution {
public:
    void solve(int i,int target,vector<int> &ds,vector<vector<int>> &ans,vector<int> &arr)
{
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }
    for(int j=i;j<arr.size();j++)
    {
        if(j>i && arr[j]==arr[j-1]) continue;
        if(arr[j]>target) break;
        ds.push_back(arr[j]);
        solve(j+1,target-arr[j],ds,ans,arr);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0,target,ds,ans,arr);
    
    return ans;
}
};