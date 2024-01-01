class Solution {
public:
    bool isPossible(vector<int>& arr,long long days,int m,int k){
        long long noOfBks=0,count=0;
        for(int x:arr){
            if(x<=days)    count++;
            else{
                noOfBks+=(count/k);
                count=0;
            }
        }
        noOfBks+=(count/k);
        return (noOfBks>=m);
    }
    int minDays(vector<int>& arr, int m, int k) {
        int max=*max_element(arr.begin(),arr.end());
        int n=arr.size();
        if(n<((long long)m*(long long)k)) return -1;
        int low=1,high=max,ans=max;
        while(low<=high){
            long long mid=(low+high)/2;
            bool can=isPossible(arr,mid,m,k);
            if(can){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};