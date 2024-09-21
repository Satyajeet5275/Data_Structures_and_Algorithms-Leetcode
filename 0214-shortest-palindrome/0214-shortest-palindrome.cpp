class Solution {
public:
    string shortestPalindrome(string str) {
        string org=str;
        reverse(str.begin(),str.end());
        string s=org+"*"+str;
        int i=0,j=1;
        int n=str.size();
        vector<int> lps(2*n+1);
        while(j<s.size()){
            if(s[i]==s[j]){
                lps[j]=i+1;
                i++;
                j++;
            }
            if(j==s.size()) break;
            if(s[i]!=s[j]){
                if(i>0){
                    i=lps[i-1];
                }
                else{
                    lps[j]=0;
                    j++;
                }
            }
        }
        int diff=n-lps[2*n];
        string ans=str.substr(0,diff)+org;
        return ans;
    }
};