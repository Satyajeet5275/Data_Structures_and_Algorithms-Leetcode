class Solution {
public:
    long long count(vector<int>& arr, int limit){
        long long sum=0,day=1;
        for(int x:arr){
            if((sum+x)>limit){
                day++;
                sum=x;
            }
            else sum+=x;
        }
        return day;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            long long reqDays=count(arr,mid);
            if(reqDays<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};