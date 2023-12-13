class Solution {
public:
    bool isSpecial(int i,int j,int n,int m,vector<vector<int>>& mat){
        for(int x=0;x<n;x++){
            if(x==i) continue;
            if(mat[x][j]==1) return false;
        }
        for(int x=0;x<m;x++){
            if(x==j) continue;
            if(mat[i][x]==1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && isSpecial(i,j,n,m,mat)){
                    count++;
                }
            }
        }
        return count;
    }
};