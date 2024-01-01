class Solution {
public:
    int mySqrt(int n) {
        int low=0,high=n,ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long sqrt=mid*mid;
            if(sqrt<=n){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};