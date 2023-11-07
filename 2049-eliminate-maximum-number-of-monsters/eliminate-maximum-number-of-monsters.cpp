class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int killed=1,n=dist.size();
        vector<int> reach(n);
        for(int i=0;i<n;i++){
            reach[i]=ceil((float)dist[i]/(float)speed[i]);
        }
        sort(reach.begin(),reach.end());
        for(int i=0;i<n;i++) cout<<reach[i]<<" ";
        for(int i=1;i<n;i++){
            if(reach[i]-killed <= 0){
                break;
            }
            else killed++;
        }
        return killed;
    }
};
