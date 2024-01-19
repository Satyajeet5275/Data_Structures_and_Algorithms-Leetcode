class Solution {
public:
    long long minimumCost(string src, string target, vector<char>& org, vector<char>& chg, vector<int>& cost) {
        vector<vector<long long>> dist(26,vector<long long>(26,1e9));
        for(int i=0;i<chg.size();i++){
            int node1=org[i]-'a';
            int node2=chg[i]-'a';
            dist[node1][node2]=min(dist[node1][node2],(long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        long long req=0;
        for(int i=0;i<src.size();i++){
            if(src[i]==target[i]) continue;
            int node1=src[i]-'a';
            int node2=target[i]-'a';
            if(dist[node1][node2]==1e9) return -1;
            req+=dist[node1][node2];
        }
        return req;
    }
};