class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int rs5=0,rs10=0,rs20=0;
        for(auto x: bills){
            if(x==5) rs5++;
            else if(x==10 && rs5>=1){
                rs5--;
                rs10++;
            }
            else if(x==20 && ((rs10>=1 && rs5>=1) || rs5>=3)){
                if(rs10>=1 && rs5>=1){
                    rs5--;
                    rs10--;
                }
                else if(rs5>=3){
                    rs5-=3;
                }
                rs20++;
            }
            else return false;
        }
        return true;
    }
};