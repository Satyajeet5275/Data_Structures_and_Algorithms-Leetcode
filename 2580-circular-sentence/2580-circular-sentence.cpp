class Solution {
public:
    bool isCircularSentence(string s) {
        if (s[0] != s[s.size() - 1])    return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (s[i - 1] != s[i + 1])
                    return false;
            }
        }
        return true;
    }
};