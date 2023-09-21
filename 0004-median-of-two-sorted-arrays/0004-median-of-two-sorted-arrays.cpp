class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1);
        arr.insert(arr.end(),nums2.begin(),nums2.end());
        sort(arr.begin(),arr.end());
        
        if(arr.size()==1)
        {
            return arr[0];
        }
        else if(arr.size()==2)
        {
            return (arr[0]+arr[1])/2.0000;
        }
        int m=arr.size()/2;
        cout<<m;
        double median=0;
        if(arr.size()%2!=0)
        {
            median=arr[m];
        }
        else
        {
            int l=(arr.size()/2)-1;
            int r=arr.size()/2;
            median=(((double)arr[l])+(double)arr[r])/2.0000;
        }
        
        return median;
    }
};