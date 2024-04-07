class Solution {
public:
    int findMid(vector<int>& arr,int& n){
            return round(arr[n/2]);
    }
    long long minOperationsToMakeMedianK(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mid=findMid(arr,n);
        if(mid==k) return 0;
        long long ans=0;
        int pos=n/2;
        cout<<mid;
        if(mid<k){
            while(pos<n && arr[pos]<k){
                ans+=k-arr[pos];
                pos++;
            }
            
        }
        else if(mid>k){
            while(pos>=0 && arr[pos]>k){
                ans+=arr[pos]-k;
                pos--;
            }
        }
        return ans;
    }
};