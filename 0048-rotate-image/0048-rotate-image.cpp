class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int x=0,y=n-1;
            while(x<y){
                swap(mat[i][x],mat[i][y]);
                x++;
                y--;
            }
        }
    }
};

