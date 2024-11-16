class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<=n-k;i++){
            int maxi=nums[i];
            bool flag=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j-1]+1!=nums[j]) flag=false;
                else maxi=nums[j];
            }
            if(flag) res.push_back(maxi);
            else res.push_back(-1);
        }
        return res;
    }
};