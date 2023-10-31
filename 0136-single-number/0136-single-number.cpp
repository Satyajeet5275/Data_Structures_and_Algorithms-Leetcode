class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        
        int size=nums.size();
        
        for(int i=0;i<size;i++)
        {
            m[nums[i]]=0;
        }
        
        for(int i=0;i<size;i++)
        {
            m[nums[i]]++;   
        }
        
        for(int i=0;i<size;i++)
        {
            if(m[nums[i]]==1)
            {
                return nums[i];
            }
        }
        
        return 0;
    }
    };