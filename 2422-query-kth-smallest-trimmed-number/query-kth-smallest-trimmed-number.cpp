#include<stdio.h>
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int digs=nums[0].size(),n=nums.size();
        vector<vector<pair<string,int>>> trimmed(digs);
        char *endptr;
        for(int i=0;i<n;i++){
            for(int j=0;j<digs;j++){
                string trim=nums[i].substr(j);
                // stringstream in;
                // in << trim;
                // long long int num;
                // in >> num;
                trimmed[j].push_back({trim,i});
            }
        }
        cout<<digs;
        for(int j=0;j<digs;j++){
            sort(trimmed[j].begin(),trimmed[j].end());
        }
        vector<int> ans;
        for(auto q:queries){
            int k=q[0],trim=q[1];
            int loc=digs-trim;
            ans.push_back(trimmed[loc][k-1].second);
        }
        return ans;
    }
};