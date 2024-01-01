class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x) {
        int low=0,high=n-1,ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                high=mid-1;
                ans=min(ans,mid);
            }
            else low=mid+1;
        }
        return ans;
    }
    int upperBound(vector<int> &arr, int n, int x){	
        int low=0,high=n-1,ans=n;
        while(low<=high){
            int mid=(low+high)/2;	
            if(arr[mid]>x){
                ans=mid;
                high=mid-1;
            }
            else    low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lower=lowerBound(nums,n,target);
        int upper=upperBound(nums,n,target);
        if(lower==n || nums[lower]!=target) return {-1,-1};
        return {lower,upper-1};
    }
};