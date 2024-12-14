class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert({nums[i], i});
        }
        long long score = 0;
        while(st.size() > 0) {
            auto it = st.begin();
            int val = it->first;
            int idx = it->second;
            st.erase(it);
            score+=val;
            if(idx-1>=0 ){
                if(st.find({nums[idx-1], idx-1}) != st.end()) {
                    st.erase({nums[idx-1], idx-1});
                }
            }
            if(idx+1 < nums.size()) {
                if(st.find({nums[idx+1], idx+1}) != st.end()) {
                    st.erase({nums[idx+1], idx+1});
                }
            }
        }
        return score;
    }
};