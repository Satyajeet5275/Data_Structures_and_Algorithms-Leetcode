class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        int n=s.length();
        long long ans=n%mod;
        long count=1;
        for(int i=0;i<n;i++){
            if(i<n &&s[i]==s[i+1]){
                count=(count+1)%mod;
            }
            else if(count>1){
                ans=(ans+(count*(count-1)/2))%mod;
                count=1;
            }
        }
        return (int)ans;
    }
};