class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allcap=1;
        for(int i=1;i<word.length();i++)
        {
            if(word[i]<=90 && word[i-1]>90) return false;
            if(word[i]>90 && word[i-1]<=90 && i>1) return false;
        }
        return true;
    }
};