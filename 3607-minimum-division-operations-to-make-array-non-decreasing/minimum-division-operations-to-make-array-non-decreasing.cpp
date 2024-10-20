#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
    int divisor(int n) {
        int div = 1;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (i < n) div = max(div, i);
                if (n / i < n && n / i != n) div = max(div, n / i);
            }
        }
        return div;
    }

public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for (int i = n - 2; i >= 0; i--) {
            while (nums[i] > nums[i + 1]) {
                int gpd = divisor(nums[i]);
                
                if (gpd == 1 && nums[i] != 1) {
                    return -1;
                }
                
                ans++;
                nums[i] /= gpd;
            }
        }
        
        return ans;
    }
};
