class Solution {
public:
    vector<string> split(string s) {
        stringstream ss(s);
        string tok;
        vector<string> tokens;
        while (getline(ss, tok,',')) {
            tokens.push_back(tok);
        }
        return tokens;
    }
    bool isValidSerialization(string pre) {
        vector<string> tokens=split(pre);
        stack<string> st;
        for(string tok:tokens){
            if(tok=="#"){
                while(st.size()>=2 && st.top()=="#"){
                    st.pop();
                    if(st.top()!="#") st.pop();
                }
            }
            st.push(tok);
        }
        return st.size()==1 && st.top()=="#";
    }
};