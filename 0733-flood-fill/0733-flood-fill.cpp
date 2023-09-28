class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int target = img[sr][sc];
        int n=img.size();
        int m=img[0].size();

        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        img[sr][sc]=color;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    img[nrow][ncol]==target && img[nrow][ncol]!=color )
                {
                    q.push({nrow,ncol});
                    img[nrow][ncol]=color;
                }
            }
        }
        return img;
    }
};