class Solution {
public:
    string reversePrefix(string word, char ch) {
        string pre="";
        int i=0;
        while(word[i]!=ch && i<word.length()){
            pre = word[i++] + pre;
        }
        if(i==word.length()) return word;
        pre = word[i++] + pre;
        while(i<word.length()){
            pre+=word[i++];
        }
        return pre;
    }
};