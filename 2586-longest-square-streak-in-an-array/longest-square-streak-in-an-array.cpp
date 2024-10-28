class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums) st.insert(x);
        int maxStreak = 0;
        
        for(auto x: nums) {
            long long square = (long long)x * x;
            int streak = 1;
            
            while(square <= INT_MAX && st.find((int)square) != st.end()) {
                streak++;
                square = (long long)square * square;
            }
            
            maxStreak = max(maxStreak, streak);
        }
        
        return maxStreak == 1 ? -1 : maxStreak;
    }
};
