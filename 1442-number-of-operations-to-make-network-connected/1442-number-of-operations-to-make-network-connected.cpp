class DisjointSet
{
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            size.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        int find_parent(int node)
        {
            if(parent[node]==node)
                return node;
            parent[node]=find_parent(parent[node]);
            return(find_parent(parent[node]));
        }
        void union_by_rank(int u,int v)
        {
            int pv = find_parent(v);
            int pu = find_parent(u);
            if(pv==pu)  
                return;
            if(rank[pv]<rank[pu])
            {
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu])
            {
                parent[pu]=pv;
            }
            else
            {
                parent[pv]=pu;
                rank[pu]++;
            }
        }
        void union_by_size(int u,int v)
        {
            int pv = find_parent(v);
            int pu = find_parent(u);
            if(pv==pu)  
                return;

            if(size[pv]<size[pu])  {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            else {  
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int extra=0;
        
        for(auto x:edge){
            int u=x[0];
            int v=x[1];
            if(ds.find_parent(u)==ds.find_parent(v)) extra++;
            else ds.union_by_size(u,v);
        }
        
        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) comp++;
        }
        if(comp-1>extra) return -1;
        return (comp-1);
    }
};