class Solution {
public:
    int pivotInteger(int n) {
        int l=1,h=n;
        while(l<=h) {
            int mid=(l+h)/2;
            int uptoMid=(mid*(mid+1))/2;
            int afterMid=(n*(n+1))/2;
            afterMid-=uptoMid;
            afterMid+=mid;
            cout<<mid<<" ";
            if(afterMid==uptoMid) return mid;
            else if(afterMid>uptoMid) l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};