class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto x:arr) mp[(x%k+k)%k]++;

        for(auto x:arr){
            int rem=(x%k+k)%k;
            if(rem==0 && mp[rem]%2==1) return false;
            else if(rem!=0 && mp[rem]!=mp[k-rem]) return false;
        }
        return true;
    }
};