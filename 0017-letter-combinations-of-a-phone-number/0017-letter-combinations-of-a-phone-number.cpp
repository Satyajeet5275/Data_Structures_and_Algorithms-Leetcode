class Solution {
public:
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

    void solve(int ind,string& op,string digits)
    {
        if(ind>=digits.size()){
            ans.push_back(op);
            return;
        }
        int dig=digits[ind]-'0';
        for(int i=0;i<map[dig].length();i++)
        {
            solve(ind+1,op+=map[dig][i],digits);
            op.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string op;
        if (digits.size()>0) solve(0,op,digits);
        return ans;       
    }
};