class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);


        for(int x=0;x<=n;x++)
        {
            int i=x;
            while(i>0)
            {
                if(i&1) ans[x]=ans[x]+1;
                i=i>>1;
            }
        }
        return ans;
    }
};