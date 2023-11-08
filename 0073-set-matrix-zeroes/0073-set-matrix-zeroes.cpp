class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>> loc;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) {
                loc.push_back({i,j});
                cout<<i<<" "<<j<<endl;
                }
            }
        }
        for(auto it:loc){
            int x=it.first;
            int y=it.second;
            for(int i=0;i<n;i++)
                mat[i][y]=0;
            for(int i=0;i<m;i++)
                mat[x][i]=0;
            
            
        }
    }
};