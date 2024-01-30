class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens) {
            if(s.length()==1 && s[0]<=47) {
                int res=0;
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(s=="*") res=num1*num2;
                else if(s=="+") res=num1+num2;
                else if(s=="-") res=num1-num2;
                else if(s=="/") res=num1/num2;
                st.push(res);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};