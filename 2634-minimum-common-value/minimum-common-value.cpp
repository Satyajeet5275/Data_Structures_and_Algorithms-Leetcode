class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp1;
        for(auto x:arr1) mp1[x]++;
        for(auto x:arr2){
            if(mp1[x]>0) return x;
        }
        return -1;
    }
};