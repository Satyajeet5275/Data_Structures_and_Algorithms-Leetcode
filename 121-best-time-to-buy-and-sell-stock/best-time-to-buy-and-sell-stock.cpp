class Solution {
public:
    int maxProfit(vector<int>& stk) {
        int mini=stk[0],cost=0,ans=INT_MIN;
        for(int i=0;i<stk.size();i++)
        {
            cost=stk[i]-mini;
            ans=max(cost,ans);
            mini=min(mini,stk[i]);
        }
        return ans;
    }
};