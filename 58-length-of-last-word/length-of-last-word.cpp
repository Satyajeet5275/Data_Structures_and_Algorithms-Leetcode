class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int ind=n-1;
        while(ind>=0 && s[ind]==' ') {
            ind--;
        }
        int ans=0;
        while(ind>=0 && s[ind]!=' '){
            ans++;
            ind--;
        }
        return ans;
    }
};