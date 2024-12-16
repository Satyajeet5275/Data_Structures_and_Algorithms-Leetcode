class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int val=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            pq.push({val*mul,idx});
        }
        vector<int> ans(n);
        while(pq.size()!=0){
            int val=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            ans[idx]=val;
        }
        return ans;
    }
};