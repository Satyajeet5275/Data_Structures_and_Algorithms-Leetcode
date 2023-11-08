class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        
        unordered_set<int> st;
        for(int i=0;i<n;i++)
            st.insert(nums[i]);
        int maxi=INT_MIN;
        for(auto it:st){
            if(st.find(it-1)!=st.end()) continue;
            int count=0;
            int x=it;
            while(st.find(x)!=st.end()){
                count++;
                x++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};