#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxBeauty = 1; // Variable to track the maximum size of a valid subsequence

        // Step 2: Iterate through each element
        for (int i = 0; i < n; i++) {
            // Find the upper bound index where nums[j] > nums[i] + 2 * k
            auto ub = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);
            // Update maxBeauty with the size of the current valid subsequence
            maxBeauty = max(maxBeauty, static_cast<int>(ub - (nums.begin() + i)));
        }
        return maxBeauty; // Return the maximum valid subsequence size
    }
};
