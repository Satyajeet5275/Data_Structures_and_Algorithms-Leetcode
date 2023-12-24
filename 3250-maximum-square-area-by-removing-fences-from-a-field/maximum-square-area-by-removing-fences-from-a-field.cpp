class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        v.push_back(1);
        v.push_back(n);
        h.push_back(1);
        h.push_back(m);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        unordered_set<int> s1,s2;
        for(int i=0;i<h.size();i++){
            for(int j=i+1;j<h.size();j++){
                s1.insert((h[j]-h[i]));
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                s2.insert((v[j]-v[i]));
            }
        }
        long long ans=0;
        for(int x:s1){
            if(s2.find(x)!=s2.end()){
                long long area=(long long)x*(long long)x;
                ans=max(ans,area);
            }
        }
        if(ans==0) return -1;
        return (int)(ans%mod);
    }
};