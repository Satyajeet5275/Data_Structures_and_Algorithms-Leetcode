class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x:nums) pq.push(x);
        long long ans=0;
        while(k--){
            int ele=pq.top();
            pq.pop();
            pq.push(ceil(ele/3.0));
            ans+=ele;
        }
        return ans;
    }
};