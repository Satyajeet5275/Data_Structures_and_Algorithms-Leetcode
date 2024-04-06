class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]==')') {
                if(st.empty()) {
                    s.erase(i,1);
                    i--;
                }
                else if(st.top().first=='('){
                    st.pop();
                }
            }
            else if(s[i]=='('){
                st.push({'(',i});
            }
        }
        while(!st.empty()) {
            s.erase(st.top().second,1);
            st.pop();
        }
        return s;
    }
};