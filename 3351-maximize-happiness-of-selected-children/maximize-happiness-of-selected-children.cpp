class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k) {
        sort(happ.begin(),happ.end());
        reverse(happ.begin(),happ.end());
        long long ans=0,i=0,n=happ.size(),red=0;
        while(i<n && k--){
            // cout<<happ[i]<<"->"<<i<<endl;
            if(happ[i]<i) break;
            ans+=happ[i];
            ans-=i;
            i++;
        }
        return ans;
    }
};