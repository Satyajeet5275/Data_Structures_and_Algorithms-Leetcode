class Solution {
public:
    long long minimumSteps(string s) {
        int i=0,j=s.length()-1;
        while(i<s.length() && s[i]=='0')   i++;
        while(j>=0 && s[j]=='1')    j--;
        if(j<=i) return 0;
        int zeros=0,ptr=j;
        long long ans=0;
        while(ptr>=0 ){
            if(s[ptr]=='0') zeros++;
            else{
                ans+=zeros;
            }
            ptr--;
        }

        return ans;
    }
};