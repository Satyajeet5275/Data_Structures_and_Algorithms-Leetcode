class Solution {
public:
    long long count(vector<int>& arr, int divisor){
        long long sum=0;
        for(int x:arr){
            sum+=ceil((double)x/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int max=*max_element(arr.begin(),arr.end());
        int low=1,high=max,ans=max;
        while(low<=high){
            int mid=(low+high)/2;
            long long sum=count(arr,mid);
            if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};