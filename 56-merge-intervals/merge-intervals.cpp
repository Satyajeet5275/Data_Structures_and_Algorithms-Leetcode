class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& slots) {
        sort(slots.begin(),slots.end());
        for(int i=0;i<slots.size()-1;i++){
            if(slots[i][1]>=slots[i+1][0]) {
                slots[i][1]=max(slots[i][1],slots[i+1][1]);
                slots.erase(slots.begin()+i+1);
                i--;
            }
        }
        return slots;
    }
};