class Solution {
public:

    bool isCycle(int src,vector<vector<int>> & edges,vector<bool>&vis,vector<bool> &rec){

        vis[src]=true;
        rec[src]=true;

        for(int i = 0 ;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][0];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v,edges,vis,rec)) return true;
                }else if(rec[v]){
                    return true;
                }
            }
        }
        rec[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false),rec(n,false);
       for( int i =0 ;i<n ;i++){
        if(!vis[i]){
            if(isCycle(i,edges,vis,rec)){
                return false;
            }
        }
       }
       return true;
    }
};