class Solution {
public:
    static bool compair(string s1,string s2){
        if(s1.size()==s2.size()) return s1<s2;
        return s1.size()>s2.size();
    }
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(),dict.end(),compair);
        for(auto wd:dict){
            int n=wd.size();
            int count=0,st1=0;
            for(int i=0;i<s.length();i++){
                if(s[i]==wd[st1]){
                    count++;
                    st1++;
                }
                if(count==n) return wd;
            }
        }
        return "";
    }
};