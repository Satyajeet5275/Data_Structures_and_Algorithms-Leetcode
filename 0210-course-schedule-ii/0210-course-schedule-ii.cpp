class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& edge) {
        vector<vector<int>> adj(N);
	    vector<int> indegree(N,0);
	    for(auto x:edge){
	        int v=x[0];
	        int u=x[1];
	        indegree[v]++;
	        adj[u].push_back(v);
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto x:adj[node]){
	            indegree[x]--;
	            if(indegree[x]==0){
	                q.push(x);
	            }
	        }
	    }
	    if(ans.size()==N) return ans;
	    return {};
    }
};