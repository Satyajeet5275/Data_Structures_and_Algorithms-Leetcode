class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
         int col=mat[0].size()-1;
        int row=0;
        while(col>=0 && col<mat[0].size() && row<mat.size())
        {
            if(mat[row][col]==target)
                return true;
            else if(mat[row][col]<target)
            {
                    row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};