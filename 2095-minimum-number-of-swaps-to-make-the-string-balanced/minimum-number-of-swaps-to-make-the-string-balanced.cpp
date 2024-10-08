class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, swap = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[')
                open++;
            else
                close++;

            if (close > open) {
                swap++;
                open++;
                close--;
            }
        }
        return swap;
    }
};