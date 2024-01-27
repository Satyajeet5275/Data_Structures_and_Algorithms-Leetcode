class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x>y) return longestString(y,x,z);
        int fget=x*2;
        y-=x;
        int sget=0;
        if(y>0) sget=z+1;
        else sget=z;
        int total= fget+sget;
        return total*2;
    }
};