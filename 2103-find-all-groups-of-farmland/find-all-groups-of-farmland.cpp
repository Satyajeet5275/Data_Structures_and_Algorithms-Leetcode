class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    vector<int> dfs(int i, int j, vector<vector<int>>& land, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        int tx = i, ty = j, bx = i, by = j;
        vector<int> tmp; 
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && ny >= 0 && nx < land.size() && ny < land[0].size() && !vis[nx][ny] && land[nx][ny]==1) {
                tmp = dfs(nx, ny, land, vis);
                if (bx < tmp[2]) {
                    bx = tmp[2];
                    by = tmp[3];
                }
                else if(bx == tmp[2]) by=max(by,tmp[3]);
            }
        }
        return {i, j, bx, by};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)), ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    ans.push_back(dfs(i, j, land, vis));
                }
            }
        }
        return ans;
    }
};
