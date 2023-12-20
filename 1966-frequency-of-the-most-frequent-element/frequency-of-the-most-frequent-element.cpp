class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long l=0,ans=1;;
        long current=0;

        for(int r=0;r<n;r++){
            current+=arr[r];
            long len=r-l+1;
            while((arr[r]*len)>(k+current)){
                current-=arr[l];
                l++;
                len=r-l+1;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};