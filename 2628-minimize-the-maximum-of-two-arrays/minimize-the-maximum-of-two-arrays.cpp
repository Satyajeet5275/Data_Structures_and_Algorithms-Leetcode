class Solution {
public:
    int minimizeSet(int div1, int div2, int n, int m) {
        int low=0,high=INT_MAX;
        int gcd=__gcd(div1,div2);
        long long int lcm=((long long)div1*div2)/gcd;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int divBy1=mid-(mid/div1);
            int divBy2=mid-(mid/div2);
            int commonDiv=mid-(mid/lcm);
            if(divBy1>=n && divBy2>=m && commonDiv>=(n+m)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};