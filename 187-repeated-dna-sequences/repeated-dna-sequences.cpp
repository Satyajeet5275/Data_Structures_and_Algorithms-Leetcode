class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int n=s.length();
        for(int i=0;i<=n-10;i++){
            string str=s.substr(i,10);
            mp[str]++;
        }
        // if(n<=20 && n>10 && s.substr(0,n/2)==s.substr(n/2,n/2)) return {s.substr(0,10)};
        vector<string> ans;
        for(auto x:mp){
            if(x.second>1) ans.push_back(x.first);
        }
        return ans;
    }
};