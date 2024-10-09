class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char> st;
       for(auto x:s){
            char ch=st.top();
            if(x==')'){
                if(!st.empty() && x!=st.top()) st.pop();
                else st.push(x);
            }
            else st.push(x);
       }
       return st.size();
    }
};