class Solution {
public:
    int countBit(int n)
    {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& arr) {
        int n=arr.size();
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr[j + 1] && countBit(arr[j])==countBit(arr[j+1])) 
                    swap(arr[j], arr[j + 1]); 
            }
        }  
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) return false;
        }
        return true;
    }
};