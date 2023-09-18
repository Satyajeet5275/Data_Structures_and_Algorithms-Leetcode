class Solution {
public:
    void solve(int i,int target,vector<int> &ds,vector<vector<int>> &ans,vector<int> &arr)
{
    if(i==arr.size())
    {
        if(target==0)   ans.push_back(ds);
        return;
    }
    if(arr[i]<=target)
    {
        ds.push_back(arr[i]);
        solve(i,target-arr[i],ds,ans,arr);
        ds.pop_back();
    }
    solve(i+1,target,ds,ans,arr);

}
vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0,target,ds,ans,arr);
    
    return ans;
}
};