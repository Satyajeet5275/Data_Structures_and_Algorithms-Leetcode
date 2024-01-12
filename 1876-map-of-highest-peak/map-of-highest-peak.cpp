class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    vis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(vis[nx][ny]==-1){
                        vis[nx][ny]=(vis[x][y]+1);
                        q.push({nx,ny});
                    }
                }
            }
        }
        return vis;
    }
};