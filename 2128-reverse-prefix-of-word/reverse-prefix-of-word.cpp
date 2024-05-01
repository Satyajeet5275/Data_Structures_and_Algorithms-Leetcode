class Solution {
public:
    string reversePrefix(string word, char ch) {
        string pre="";
        int i=0;
        while(word[i]!=ch && i<word.length()){
            pre.insert(0,""+string(1,word[i]));
            i++;
        }
        if(i==word.length()) return word;
        pre.insert(0,""+string(1,word[i]));
        i++;
        while(i<word.length()){
            pre+=word[i];
            i++;
        }
        return pre;
    }
};