class Solution {
public:
    int maxEle(int mid,vector<vector<int>>& mat){
        int maxi=-1,loc=0;
        for(int i=0;i<mat.size();i++){
            if(maxi<mat[i][mid]){
                loc=i;
                maxi=mat[i][mid];
            }
        }
        return loc;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int loc=maxEle(mid,mat);
            int val=mat[loc][mid];
            int left= (mid>0) ? mat[loc][mid-1] : -1;
            int right= (mid<m-1) ? mat[loc][mid+1] : -1;
            if(left<val && right<val) return {loc,mid};
            if(left>val) high=mid-1;
            else if(right>val) low=mid+1;
        }
        return {-1,-1};
    }
};

// [[25,37,23,37,19],
//  [45,19,2 ,43,26],
//  [18, 1,37,44,50]]