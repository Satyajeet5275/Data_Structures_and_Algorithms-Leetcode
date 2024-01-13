class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        if(n%2!=0){
            int req=nums[(n/2)];
            for(int i=0;i<n;i++){
                count+=abs(req-nums[i]);
            }
        }
        else{
            int mid1=nums[(n/2)-1];
            int mid2=nums[(n/2)];
            int req=(mid1+mid2)/2;
            for(int i=0;i<n;i++){
                count+=abs(req-nums[i]);
            }
        }
        return count;
    }
};