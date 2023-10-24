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
            else {      //if(size[pv]>size[pu])
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};


class Solution {
  public:
    int removeStones(vector<vector<int>>& stones) {
        // Code here
        int n=stones.size();
        int maxrow = 0 ;
        int maxcol = 0 ;
        for(auto it:stones)
        {
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int,int> nodes;
        
        for(auto it:stones){
            int row = it[0];
            int col = it[1]+maxrow+1;
            ds.union_by_size(row,col);
            nodes[row] = 1;
            nodes[col] = 1;
        }
        int cnt = 0;
        for(auto it : nodes)
        {
            int node = it.first;
            if(ds.find_parent(node) == node){
                cnt++;
            }
        }
        return n-cnt;
    }
};