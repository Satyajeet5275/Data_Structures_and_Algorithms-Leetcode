class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int index = -1;

       for(int i=n-1;i>0;i--)
       {
           if(nums[i] > nums[i-1])
           {
               index = i;
               break;
           }
       }

        // cout << index <<endl;
       if(index == -1) 
       {
           sort(nums.begin(), nums.end());
           return;
       }

       int maxi = INT_MAX;
       int pos = -1;

       for(int i=index;i<n;i++)
       {
           
           if(nums[index-1] < nums[i] && nums[i] < maxi)
           {
               maxi = nums[i];
                pos = i;
           }
       }

        cout << pos <<endl;
       swap(nums[index-1], nums[pos]);
       sort(nums.begin()+index, nums.end());

    }
};