class Solution {
public:
    int bagOfTokensScore(vector<int>& tkn, int power) {
        sort(tkn.begin(),tkn.end());
        int n=tkn.size(),st=0,en=n-1;
        int score=0,maxi=0;
        if(n==0 || power<tkn[0]) return 0;
        if(n==1) return 1;
        while(st<en){
            while(power>=tkn[st]){
                power-=tkn[st];
                st++;
                score++;
            }
            maxi=max(maxi,score);
            power+=tkn[en];
            en--;
            score--;
        }
        return maxi;
    }
};