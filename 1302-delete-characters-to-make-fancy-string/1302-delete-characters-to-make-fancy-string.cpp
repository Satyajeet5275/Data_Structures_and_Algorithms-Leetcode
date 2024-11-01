class Solution {
public:
    string makeFancyString(string s) {
        for(int i=2;i<s.length();i++){
            int cont=0;
            int start=i;
            while(s[i]==s[i-1] && s[i-1]==s[i-2]){
               cont++;
               i++;
            }
            i=start;
            s.erase(start,cont);
        }
        return s;
    }
};