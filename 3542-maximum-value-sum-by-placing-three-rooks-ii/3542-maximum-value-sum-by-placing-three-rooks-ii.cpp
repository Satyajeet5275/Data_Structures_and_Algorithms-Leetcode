class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<pair<int,int>>> top3(n);
        vector<pair<int,pair<int,int>>> all;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                top3[i].push_back({arr[i][j],j});
                all.push_back({arr[i][j],{i,j}});
            }
            sort(top3[i].rbegin(),top3[i].rend());
        }
        sort(all.rbegin(),all.rend());
        long long ans=-1e10;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(top3[i][a].second==top3[j][b].second) continue;
                        for(auto x:all){
                            if(x.second.first != i && x.second.first != j
                            && x.second.second != top3[i][a].second && x.second.second != top3[j][b].second)
                            {
                                ans=max(ans,(long long)top3[i][a].first+top3[j][b].first+x.first);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};