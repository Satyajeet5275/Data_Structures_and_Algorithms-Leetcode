class Solution {
public:
    long long maxEnergyBoost(vector<int>& ed1, vector<int>& ed2) {
        int n = ed1.size();
        vector<long long> dpA(n,0), dpB(n,0);
        dpA[0]= ed1[0];
        dpB[0]= ed2[0];
        for (int i=1;i<n;i++) {
           dpA[i]= max(dpA[i-1]+ed1[i],dpB[i-1]);
           dpB[i]= max(dpB[i-1]+ed2[i],dpA[i-1]);
        }
        return max(dpA[n-1],dpB[n-1]);
    }
};
