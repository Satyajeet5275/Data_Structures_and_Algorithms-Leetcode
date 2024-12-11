class Solution {
public:
    bool check(int mid,vector<int>& nums, int k){
        for(int i=0;i<nums.size();i++){
            int count=0;
            // for(int j=i;j<nums.size();j++){
                // if((nums[j]-nums[i])<=2*k){
                //     count++;
                // }
                // else break;
            // }
            auto ub = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);
            
            count = static_cast<int>(ub - (nums.begin() + i));
            
            if(count>=mid) return true;
        }
        return false;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int low=1,high=n,ans=1;
        sort(nums.begin(),nums.end());
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(check(mid,nums,k)){
        //         low=mid+1;
        //         ans=max(ans,mid);
        //     }
        //     else{
        //         high=mid-1;
        //     }
        // }
        int maxi=1;
          for(int i=0;i<nums.size();i++){
            int count=0;
            auto ub = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);
            maxi = max(maxi,static_cast<int>(ub - (nums.begin() + i)));
        }
        return maxi;
    }
};