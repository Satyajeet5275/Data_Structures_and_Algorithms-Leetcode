class Solution {
public:
    void reverseString(vector<char>& str) {
        int s=0,e=str.size()-1;
        while(s<e){
            char tmp=str[s];
            str[s]=str[e];
            str[e]=tmp;
            s++;
            e--;
        }
    }
};