class Solution {
public:

    bool isPalindrome(int x) {
        if(x<0) return 0;
        int dig,temp;
        long long rev=0;
        temp=x;
        while(x)
        {
            dig=x%10;
            rev=(rev*10)+dig;
            x=x/10;
        }
        if(temp==rev) return 1;

        return 0;
    }
};