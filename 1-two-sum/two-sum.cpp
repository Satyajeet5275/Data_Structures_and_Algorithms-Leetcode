class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force
        // int l = 0;
        // int h = 1;
        // vector<int> ans;
        // while(l < nums.size()){
        //     while(h < nums.size()){
        //         if(nums[l] + nums[h] == target){
        //             ans.push_back(l);
        //             ans.push_back(h);
        //         }
        //         h++;
        //     }     
        //     l++;
        //     h = l + 1;
        // }
        // return ans;

        //Optimal
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(mp.find(req)!=mp.end()){
                return {mp[req],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};