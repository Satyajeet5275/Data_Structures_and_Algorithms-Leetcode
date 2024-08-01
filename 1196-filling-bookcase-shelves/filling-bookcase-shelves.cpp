class Solution {
public:
    int solve(int i,int remWidth,int maxHeight,int n,int shelfWidth,vector<vector<int>>& books,vector<vector<int>>& dp){
        if(i>=n) return maxHeight;
        
        if(dp[i][remWidth]!=-1) return dp[i][remWidth];
        int boxW=books[i][0];
        int boxH=books[i][1];
        int pick=INT_MAX,notPick=INT_MAX;
        if(remWidth>=boxW){
            pick=solve(i+1,remWidth-boxW,max(maxHeight,boxH),n,shelfWidth,books,dp);
        }
        notPick=maxHeight+solve(i+1,shelfWidth-boxW,boxH,n,shelfWidth,books,dp);
        return dp[i][remWidth]=min(pick,notPick);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>> dp(n+1,vector<int>(shelfWidth+1,-1));
        return solve(0,shelfWidth,0,n,shelfWidth,books,dp);
        // int height=0,currRem=shelfWidth,ans=0;
        // reverse(books.begin(),books.end());
        // for(auto x:books){
        //     if(currRem>=x[0]){
        //         height=max(height,x[1]);
        //         currRem-=x[0];
        //     }
        //     else{
        //         currRem=shelfWidth;
        //         ans+=height;
        //         height=0;

        //         height=max(height,x[1]);
        //         currRem-=x[0];
        //     }
        // }
        // ans+=height;
        // return ans;
    }
};