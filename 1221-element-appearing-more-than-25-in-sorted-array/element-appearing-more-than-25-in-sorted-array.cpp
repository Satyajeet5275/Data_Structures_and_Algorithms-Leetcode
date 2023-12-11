class Solution {
public:
     int findSpecialInteger(vector<int>& arr) {
        int size=arr.size();
        if(1.0>(25.00*size)/100) return arr[0];
        int occur=1;
        for(int i=1;i<size;i++){
            if(arr[i-1]==arr[i]) occur++;
            else occur=1;
            if(occur>(25.00*size)/100) return arr[i];
        }
        return 0;
    }
};