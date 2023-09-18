class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size=nums.size();
        vector<int> v;
        int count=0;
        
        for(int i=0;i<size;i++)
        {
            if(nums[i]==val)
                count++;
            else
            {
                v.push_back(nums[i]);
            }
        }
        nums=v;
        
        return v.size();
        
    }
};