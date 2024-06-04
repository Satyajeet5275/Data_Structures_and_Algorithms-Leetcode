class Solution {
public:
    int longestPalindrome(string s) {
        int maxi=0;
        int n=s.length();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        bool taken=false;
        for(auto x:mp){
            int frq=x.second;
            if(frq%2==0) maxi+=frq;
            else{
                if(!taken){
                    maxi+=frq;
                    taken=true;
                } 
                else{
                    maxi+=frq-1;
                }
            }
        }
        return maxi;
    }
};