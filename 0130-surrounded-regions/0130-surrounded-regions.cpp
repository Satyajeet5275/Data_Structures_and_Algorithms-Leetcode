class Solution {
private:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>> grid ,int n,int m){
        vis[row][col]=1;
        for(int k=0;k<4;k++){
            int nrow=row+dx[k];
            int ncol=col+dy[k];
            if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                grid[nrow][ncol]=='O' && !vis[nrow][ncol] ){
                    dfs(nrow,ncol,vis,grid,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,grid,n,m);
            }
            if(grid[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,grid,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]=='O' && !vis[0][i]){
                dfs(0,i,vis,grid,n,m);
            }
            if(grid[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,vis,grid,n,m);
            }
        }

        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j] && grid[i][j]=='O') grid[i][j]='X';
           }
        }
    }
};