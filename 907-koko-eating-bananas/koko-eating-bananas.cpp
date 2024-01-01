class Solution {
public:
    long long count(vector<int>& arr, int speed){
        long long totalHr=0;
        for(int x:arr){
            totalHr+=ceil((double)x/(double)speed);
        }
        return totalHr;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int max=*max_element(arr.begin(),arr.end());
        int low=1,high=max,ans=max;
        while(low<=high){
            int mid=(low+high)/2;
            long long reqHr=count(arr,mid);
            if(reqHr<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};