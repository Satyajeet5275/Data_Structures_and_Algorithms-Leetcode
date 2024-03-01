class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        int n=s.length();
        for(auto c:s)
        {
            if(c=='1') count++;
        }
        cout<<count;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(count==1 && i==n-1)
            {
            ans.push_back('1');
            count--;
            continue;
            }

            if(count>1) 
            {
            ans.push_back('1');
            count--;
            }
            else ans.push_back('0');

        }
        return ans;
    }
};