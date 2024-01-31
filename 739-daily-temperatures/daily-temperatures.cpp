class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        stack<int> st;
        vector<int> ans(tmp.size());
        for(int i=0;i<tmp.size();i++) {
            while(!st.empty() && tmp[st.top()]<tmp[i]) {
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};