class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                bool flag=true;
                unordered_set<int> s;
                for(int k=i;k<i+3;k++){
                    for(int x=j;x<j+3;x++){
                        s.insert(grid[k][x]);
                        if(grid[k][x]<1 || grid[k][x]>9) flag=false;
                    }
                }
                if(s.size()!=9) flag=false;

                int dig1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int dig2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

                int row1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                int row2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                int row3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

                int col1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int col2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                int col3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];

                // cout<<dig1<<"<=>"<<dig2<<"<=>"<<col1<<"<=>"<<col2<<"<=>"<<col3<<"<=>"<<row1<<"<=>"<<row2<<"<=>"<<row3<<endl;
                if(flag && dig1==dig2 && dig1==col1 && col1==col2 && col1==col3 && col1==row1 && row1==row2 && row1==row3) count++;
            }
        }
        return count;
    }
};