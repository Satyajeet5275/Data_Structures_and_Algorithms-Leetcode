class Solution {
public:
    int heightChecker(vector<int>& high) {
        vector<int> copy=high;
        int n=high.size();
        sort(copy.begin(),copy.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(high[i]!=copy[i]) ans++;
        }
        return ans;
    }
};