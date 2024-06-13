class Solution {
public:
    int minMovesToSeat(vector<int>& seat, vector<int>& std) {
        sort(std.begin(),std.end());
        sort(seat.begin(),seat.end());
        int ans=0;
        for(int i=0;i<std.size();i++){
            ans+=abs(seat[i]-std[i]);
        }
        return ans;
    }
};