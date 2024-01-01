class Solution {
public:
long long count(vector<int>& arr, int limit){
        long long studs=1,pagesHold=0;
        for(int x:arr){
            if(pagesHold+x<=limit)    pagesHold+=x;
            else{
                studs++;
                pagesHold=x;
            }
        }
        return studs;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            long long reqstuds=count(arr,mid);
            if(reqstuds>m)  low=mid+1;
            else    high=mid-1;
        }
        return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};