class Solution {
public:
    bool dfs(int src, int des ,vector<vector<int>> & adj,vector<bool> &vis){
        if(src == des) return true;
        vis[src]= true;

        for(int v : adj[src]){
            
            if(!vis[v]){
                if(dfs(v,des,adj,vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination) return true;
        vector<vector<int>> adj(n);

        for( auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n,false);
     
     return dfs(source,destination,adj,vis);
    }
};