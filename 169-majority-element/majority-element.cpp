class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int size=nums.size();
        map<int,int> m;
        for(int i=0;i<size;i++)    m[nums[i]]++;

        int lar=0;
        int loc;
        
        for(int i=0;i<size;i++){
            if(lar<m[nums[i]]){
                lar=m[nums[i]];
                loc=nums[i];
            }
        }
        
        return loc;
    }
};