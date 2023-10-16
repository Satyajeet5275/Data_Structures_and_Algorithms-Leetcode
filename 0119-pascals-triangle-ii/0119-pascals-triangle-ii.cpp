class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1,vector<int>(rowIndex+1));
        dp[0][0]=1;
        for(int i=1;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j!=0 && j!=rowIndex){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else if(j==0) dp[i][j]=dp[i-1][j];
                else if(j==i) dp[i][j]=dp[i-1][j-1];
            }
        }
        // for(auto a:dp){
        //     for(auto b:a)
        //         cout<<b<<" ";
        //     cout<<endl;
        // }
        return dp[rowIndex];
    }
};