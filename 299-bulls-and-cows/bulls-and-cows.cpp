class Solution {
public:
    string getHint(string s, string g) {
        int n=s.length();
        map<char,int> sm,gm;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]==g[i]){
                x++;
            }
            else{
                sm[s[i]]++;
                gm[g[i]]++;
            }
        }
        for(auto x:sm){
            char ch=x.first;
            int freq=x.second;
            if(gm[ch]>=0){
                y+=min(freq,gm[ch]);
            }
        }
        string ans=to_string(x)+"A"+to_string(y)+"B";
        return ans;
    }
};