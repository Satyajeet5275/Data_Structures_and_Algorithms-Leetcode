class Solution {
public:
    string makeGood(string s) {
        int i=0;
        int n=s.length();
        while(i<n-1){
            if(s[i]<=90 && s[i]+32==s[i+1]){
                s.erase(i, 2);
                if(i>0) i--;
                continue;
            }
            else if(s[i]>=97 && s[i]-32==s[i+1]){
                s.erase(i, 2);
                if(i>0) i--;
                continue;
            }
            i++;
        }
        return s;
    }
};