class Solution {
public:
    int timer=0;
    vector<vector<int>> ans;
    void tarzan(int node,int parent,vector<int> &arival,vector<int> &low,vector<int> adj[],vector<int>& vis){
        vis[node]=1;
        arival[node]=low[node]=++timer;
        for(int adjNode:adj[node]){
            if(adjNode==parent) continue;
            else if(!vis[adjNode]){
                // cout<<"I am in not visited";
                tarzan(adjNode,node,arival,low,adj,vis);
                low[node]=min(low[adjNode],low[node]);
                if(low[adjNode]>arival[node]){
                    // cout<<"I am here";
                    ans.push_back({node,adjNode});
                }
            }
            else{
                // cout<<"I am in visited";
                low[node]=min(arival[adjNode],low[node]);
            } 
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        for(auto it:con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> low(n),arival(n);
        vector<int> vis(n,0);
        tarzan(0,-1,arival,low,adj,vis);
        return ans;
    }
};