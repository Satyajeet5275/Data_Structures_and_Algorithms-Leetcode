class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int n, int m, int r, int c) {
        queue<pair<int,int>> q;
        vector<vector<int>> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        vis[r][c]=1;
        ans.push_back({r,c});
        q.push({r,c});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                // for(int j=-1;j<=1;j++){
                    int nr=r+dx[i];
                    int nc=c+dy[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0){
                        ans.push_back({nr,nc});
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                // }
            }
        }
        return ans;
    }
};