class Solution {
public:
    int reverse(int x) {
        long long dig;
        long long rev=0;
        while(x)
        {
            dig=x%10;
            rev=(rev*10)+dig;
            x=x/10;
        }
        if(INT_MAX<rev || INT_MIN>rev) return 0;
        return int(rev);
    }
};