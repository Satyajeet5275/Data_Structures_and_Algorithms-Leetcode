class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total=0;
        for(auto x:nums){
            if(x==1) total++;
        }
        nums.insert(nums.end(),nums.begin(),nums.end());
        int mini=INT_MAX;
        int n=nums.size();
        if(n==1 || n==total) return 0;
        int windowOnes=0;
        vector<int> arr(total);
        for(int i=0;i<total;i++){
            if(nums[i]==1){ 
                windowOnes++;
            }
                arr[i]=windowOnes;
        }
        mini=min(mini,(total-windowOnes));
        for(int end=total;end<n;end++){
            int start=end-total;
            if(nums[start]==1) windowOnes--;
            if(nums[end]==1) windowOnes++;
            mini=min(mini,(total-windowOnes));
        }
        return mini;
    }
};