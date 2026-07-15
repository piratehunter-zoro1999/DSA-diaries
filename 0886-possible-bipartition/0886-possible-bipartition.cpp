class Solution {
public:
    bool dfs(int src,vector<vector<int>>& adj,vector<int> &color){

        for( int v : adj[src]){
            if(color[v]==-1){
                color[v]=1-color[src];
                if(!dfs(v,adj,color)) return false;
            }else if(color[v] == color[src]) return false;
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1);

        for(auto p : dislikes){
            int u= p[0];
            int v= p[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1,-1);

        for(int i=1;i<n+1;i++){
            if(color[i]==-1){
            color[i]=0;
              if(!dfs(i,adj,color)) return false;
            }
        }
        return true;
    }
};