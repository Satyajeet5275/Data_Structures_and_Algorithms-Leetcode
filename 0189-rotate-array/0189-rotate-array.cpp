class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> temp(k);
        int i=0,j=0;
        for(i=n-k;i<n;i++){
            temp[j]=nums[i];
            j++;
        }
        for(i=n-1;i-k>=0;i--){
            nums[i]=nums[i-k];
        }
        for(i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};