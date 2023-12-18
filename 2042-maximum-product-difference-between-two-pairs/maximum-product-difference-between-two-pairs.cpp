class Solution {
public:
    int maxProductDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        return ((arr[n-1]*arr[n-2])-(arr[0]*arr[1]));
    }
};