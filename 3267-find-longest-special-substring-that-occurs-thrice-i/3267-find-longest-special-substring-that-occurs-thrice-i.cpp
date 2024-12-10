class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        if(n<3) return -1;
        map<string,int> substr;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                if(str.length()==0 || str[0]==s[j]){
                    str+=s[i];
                    substr[str]++;
                }
                else break;
            }
        }
        int len=0;
        for(auto x:substr){
            if(x.second>=3 && x.first.length()>len){
                len=x.first.length();
            }
        }
        if(len==0) return -1;
        return len;
    }
};