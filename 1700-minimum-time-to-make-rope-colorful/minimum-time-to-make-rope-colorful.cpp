class Solution {
public:
    int minCost(string clr, vector<int>& time) {
        int n=clr.size();
        int cost=0;
        for(int i=0;i<n-1;i++){
            if(clr[i]==clr[i+1]){
                if(time[i]<=time[i+1]) cost+=time[i];
                else {
                    cost+=time[i+1];
                    swap(time[i],time[i+1]);
                }
            }
        }
        return cost;
    }
};