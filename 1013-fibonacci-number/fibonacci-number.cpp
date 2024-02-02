class Solution {
public:
    int fib(int n) {
        int fno=1,sno=1;
        int ctr=1;
        if(n==0) return 0;
        while(ctr<n)
        {
            int temp=fno;
            fno=sno;
            sno+=temp;
            ctr++;
        }
        return fno;
    }
};