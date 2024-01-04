class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        int res=0;
        for(auto x:mp){
            int freq=x.second;
            if(freq<=1) return -1;
            int op=ceil((double)freq/(double)3);
            res+=op;
        }
        return res;
    }
};
