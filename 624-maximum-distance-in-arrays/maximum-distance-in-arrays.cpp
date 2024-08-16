class Solution {
public:
    int maxDistance(vector<vector<int>>& arrs) {
        int n = arrs.size();
        int prev_min=arrs[0][0],prev_max=arrs[0][arrs[0].size()-1];
        int maxDiff=0;

        for(int i=1;i<n;i++){
            int mini=arrs[i][0];
            int maxi=arrs[i][arrs[i].size()-1];
            int diff1=abs(prev_max-mini);
            int diff2=abs(maxi-prev_min);
            maxDiff=max(maxDiff,max(diff1,diff2));
            prev_min=min(prev_min,mini);
            prev_max=max(prev_max,maxi);
        }
        return maxDiff;
    }
};