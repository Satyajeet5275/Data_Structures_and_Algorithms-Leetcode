class Solution {
public:
    int sz=-1;
   
    int countWays(vector<int>& nums) {
        
        sz=nums.size();
        sort(nums.begin(),nums.end());
    
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<i+1 && nums[i+1] >i+1)
            {
                ans ++;
            }
        }
        if(nums[0]!=0) 
            ans++;
        if(nums[sz-1]<nums.size())
            ans++;
        
        
        return ans;

    }
};