class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int> rows(n);
        for(int i=0;i<n;i++){
            int count=0;
            for(char x:bank[i]){
                if(x=='1') count++;
            }
            rows[i]=count;
            // cout<<count<<endl;
        }
        int prev=rows[0],ans=0;
        for(int i=1;i<n;i++){
            if(rows[i]>0){
                ans+=prev*rows[i];
                prev=rows[i];
            }
        }
        return ans;
    }
};