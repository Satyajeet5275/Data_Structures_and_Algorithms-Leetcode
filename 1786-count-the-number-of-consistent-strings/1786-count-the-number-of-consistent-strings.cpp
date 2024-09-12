class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(char x:allowed){
            st.insert(x);
        }
        int cnt=0;
        for(auto x:words){
            bool flag=true;
            for(char y:x){
                if(st.find(y)==st.end()){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};