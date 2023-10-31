class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int i=0;
        for(auto it:mp){
            int ele=it.first;
            int rep=it.second;
            for(int j=0;j<rep;j++){
                nums[i]=ele;
                i++;
            }
        }
    }
};