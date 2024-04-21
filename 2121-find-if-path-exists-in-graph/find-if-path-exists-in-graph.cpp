class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        if(source==destination) return true;
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            for(auto x:adj[q.front()]){
                if(x==destination) return true;
                if(!vis[x]) {
                    q.push(x);
                    vis[x]=1;
                }
            }
            q.pop();
        }
        return false;
    }
};