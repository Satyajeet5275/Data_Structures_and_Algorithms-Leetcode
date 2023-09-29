class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0)
	            {
	                q.push({{i,j},0});
	                vis[i][j]=0;
	            }
	        }
	    }
	    int dx[4]={-1,0,1,0};
	    int dy[4]={0,-1,0,1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dist=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nrow=row+dx[i];
	            int ncol=col+dy[i];
	            
	            if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
	                grid[nrow][ncol]==1 && vis[nrow][ncol]==0 ){
	                    q.push({{nrow,ncol},dist+1});
	                    vis[nrow][ncol]=dist+1;
	                }
	        }
	    }
	    return vis;
    }
};