class Solution {
public:
    bool check(int mid,int& cost,vector<int>& pref){
        for(int i=mid;i<pref.size();i++){
            int start=pref[i-mid];
            int req=pref[i]-start;
            if(req<=cost) return true;
        }
        return false;
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+abs((s[i-1]-'a')-(t[i-1]-'a'));
        }
        int l=0,h=n;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,maxCost,pref)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};