class Solution {
public:
void solve(int i,int target,int k,vector<int> &ds,vector<vector<int>> &ans)
{
        if(target==0 && k==ds.size()){   
        ans.push_back(ds);
        return;
    }
    for(int j=i;j<10;j++)
    {
        if(j>target) break;
        ds.push_back(j);
        solve(j+1,target-j,k,ds,ans);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,n,k,ds,ans);
        return ans;
    }
};