class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;

        while(i<j)
        {
            if(arr[i]%2!=0 && arr[j]%2==0) swap(arr[i],arr[j]);

            if(arr[i]%2==0) i++;
            if(arr[j]%2!=0) j--;
        }

        return arr;
    }
};