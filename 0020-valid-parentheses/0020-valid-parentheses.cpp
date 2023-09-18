class Solution {
public:
    bool isValid(string s) {
        stack<char> sym;
        sym.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
        
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
            {
                sym.push(s[i]);
            }
            else
            {
                if(sym.empty())
                {
                    return 0;
                }
                
                if(s[i]==')' && sym.top()=='(')
                    sym.pop();
                else if(s[i]==']' && sym.top()=='[')
                    sym.pop();
                else if(s[i]=='}' && sym.top()=='{')
                    sym.pop();
                else 
                    return 0;
                    
            }
        }
        if(sym.empty())
        {
          return true;  
        }
        
        return false;
    }
};