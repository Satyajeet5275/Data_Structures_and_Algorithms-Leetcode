class Solution {
public:
    int solve(int currNum, vector<int>& nums, vector<int>& dp) {
        if (currNum >= dp.size()) return 0;
        if (dp[currNum] != -1) return dp[currNum];
        
        long long square = (long long)currNum * currNum;
        if (square >= dp.size()) return dp[currNum] = 0;
        
        // Binary search to find the square
        auto it = lower_bound(nums.begin(), nums.end(), square);
        if (it == nums.end() || *it != square) {
            return dp[currNum] = 0;
        }
        
        return dp[currNum] = 1 + solve(square, nums, dp);
    }
    
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = nums.back();
        vector<int> dp(maxVal + 1, -1);
        
        int maxStreak = 1;
        for (int num : nums) {
            maxStreak = max(maxStreak, 1 + solve(num, nums, dp));
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
};