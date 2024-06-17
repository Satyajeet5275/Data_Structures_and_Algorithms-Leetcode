class Solution {
public:
    bool judgeSquareSum(int c) {
       int root=sqrt(c);
       if(c==0) return 1;
       for(int i=1;i<=root;i++){
            int sq1=i*i;
            int rem=c-sq1;
            int num2=sqrt(rem);
            int ans=(num2*num2)+sq1;
            if(ans==c) return true;
       }   
        return false;
    }
};