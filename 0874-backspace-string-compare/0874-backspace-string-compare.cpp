class Solution {
public:
    string solve(string& s){
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(ans.size()!=0)
                    ans.pop_back();
                continue;
            } 
            ans+=s[i];
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string s1=solve(s);
        string s2=solve(t);
        if(s1==s2) return 1;
        return 0;
    }
};