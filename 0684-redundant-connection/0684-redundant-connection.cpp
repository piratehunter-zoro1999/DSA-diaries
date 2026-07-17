class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int src ,int des,vector<bool>&vis){
        if(src == des) return true;
     vis[src]=true;

     for(int v : adj[src]){
        if(!vis[v]){
            if(dfs(adj,v,des,vis)) return true;
        }else if(v==des) return true;
     }
     return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        vector<vector<int>>adj(n+1);
        

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            
            vector<bool> vis(n+1,0);
            if(dfs(adj,u,v,vis)){
                return {u,v};
            } 

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

       return {};
    }
};