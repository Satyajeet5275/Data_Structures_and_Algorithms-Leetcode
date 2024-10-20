#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

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

    int minOperations(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for (int i = n - 2; i >= 0; i--) {
            while (arr[i] > arr[i + 1]) {
                int gpd = divisor(arr[i]);
                if (gpd == 1 && arr[i] != 1) return -1;
                ans++;
                arr[i] /= gpd;
            }
        }

        return ans;
    }
};
