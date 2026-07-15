class Solution {
public: 
    void dfs(int src,vector<vector<int>> &adj,vector<bool> &vis){
      
      vis[src]=true;

      for(int v : adj[src]){

        if(!vis[v]){
            dfs(v,adj,vis);
        }
      }
      
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int e=connections.size();

        if(e<n-1) return -1;

        vector<vector<int>> adj(n);

        for(auto e : connections){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
             if(!vis[i]){
                dfs(i,adj,vis);
                count++;
             }
        }

      return count -1;

    }
};