class Solution {
public:
    // int findSpecialInteger(vector<int>& arr) {
    //     int size=arr.size();
    //     map<int,int> mp;
    //     for(int i=0;i<size;i++){
    //         mp[arr[i]]++;
    //     }
    //     for(auto it:mp){
    //         float percent=((float)it.second/(float)size)*100.00;
    //         if(percent>25.00) return it.first;       
    //     }
    //     return 0;
    // }
     int findSpecialInteger(vector<int>& arr) {
        int size=arr.size();
        if(size<4) return arr[0];
        int occur=1;
        for(int i=1;i<size;i++){
            if(arr[i-1]==arr[i]) occur++;
            else occur=1;
            if(occur>(25.00*size)/100) return arr[i];
        }
        return 0;
    }
};