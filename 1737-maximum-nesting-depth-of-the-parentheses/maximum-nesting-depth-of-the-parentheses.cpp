class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int dep=0,maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') dep++;
            else if(s[i]==')') dep--;
            maxi=max(maxi,dep);
        }
        return maxi;
    }
};