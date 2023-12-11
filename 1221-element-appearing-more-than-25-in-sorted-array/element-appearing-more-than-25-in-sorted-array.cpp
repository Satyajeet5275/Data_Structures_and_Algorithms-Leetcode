class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size=arr.size();
        map<int,int> mp;
        for(int i=0;i<size;i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            float percent=((float)it.second/(float)size)*100.00;
            if(percent>25.00) return it.first;       
        }
        return 0;
    }
};