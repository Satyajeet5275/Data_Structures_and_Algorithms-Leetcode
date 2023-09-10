class Solution {
public:
       int countOrders(int n) {
        long res = 1, mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
            res = res * (i * 2 - 1) * i % mod;
        return res;
    }
};

//1   6   90    2520   113400 7284400
// 5    84   2430  110880  7171000