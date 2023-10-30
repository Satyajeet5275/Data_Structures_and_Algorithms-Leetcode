class Solution {
public:
    static int countBits(int n){
        int bits=0;
        while(n){
            bits+=(n&1);
            n>>=1;
        }
        return bits;
    }
    static bool comparator(int a,int b){
        int aBits=countBits(a);
        int bBits=countBits(b);
        if(aBits==bBits)  return (a<b);
        return (aBits<bBits);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comparator);
        return arr;
    }
};