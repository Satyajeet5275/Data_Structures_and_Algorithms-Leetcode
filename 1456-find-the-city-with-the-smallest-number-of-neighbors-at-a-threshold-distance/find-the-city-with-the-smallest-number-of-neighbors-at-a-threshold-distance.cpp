class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<vector<int>> mat(n,vector<int>(n,1e9));
            for(int i=0;i<n;i++)   mat[i][i]=0;
            for(auto x:edges){
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                mat[u][v]=wt;
                mat[v][u]=wt;
            }

            //Actual Algo ->
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                            mat[i][j]=min(mat[i][j],(mat[i][k]+mat[k][j]));
                    }
                }
            }
            int mini=INT_MAX,loc=0;
            for(int i=0;i<n;i++){
                int reachable=0;
                    for(int j=0;j<n;j++){
                        if(mat[i][j]<=distanceThreshold){
                            reachable++;
                        }
                    }
                if(mini>=reachable){
                    mini=reachable;
                    loc=i;
                }
            }
            return loc;
    }
};