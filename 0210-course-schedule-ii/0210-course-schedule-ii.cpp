class Solution {
public:
    bool isCycle(int src ,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &rec){
            vis[src]= true;
            rec[src]= true;

            for(int v :adj[src]){
                if(!vis[v]){
                    if(isCycle(v,adj,vis,rec)) return true;
                }else if(rec[v]){
                    return true;
                }
            }
            rec[src]=false;
            return false;
    }

    void topo(int src,vector<vector<int>> &adj ,stack<int> &s,vector<bool> &vis){
            vis[src]=true;

            for(int v : adj[src]){
                if(!vis[v]){
                     topo(v,adj,s,vis);
                }
            }
            s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false),rec(n,false);

        vector<vector<int>> adj(n);

        for(auto &edge : edges){
            int v = edge[0];
            int u = edge[1];

            adj[u].push_back(v);
        }

        for(int i =0 ;i<n ; i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,rec)){
                    return {};
                }
            }
        }
        
        stack<int> s;
        vector<bool> check(n,false);
        for(int i=0 ;i <n ;i++){
            if(!check[i]){
                topo(i,adj,s,check);
            }
        }
        vector<int> ans;
        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};