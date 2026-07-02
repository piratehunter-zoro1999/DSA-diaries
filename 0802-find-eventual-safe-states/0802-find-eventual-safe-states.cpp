class Solution {
public:
    
     bool isCycle(int src,vector<vector<int>> & graph,vector<bool>& vis, vector<bool> & rec){
          vis[src]= true;
          rec[src]= true;

          for(int v : graph[src]){
            if(!vis[v]){
                if(isCycle(v,graph,vis,rec)){
                    return true;
                }
            }else if (rec[v]) {
                return true;
            }
          }
          rec[src]= false;

          return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> safeNodes;
        
        for(int i =0 ;i<n;i++){
            vector<bool> vis(n,false);
            vector<bool> rec(n,false);
            if(!isCycle(i,graph,vis,rec)){
                  safeNodes.push_back(i);
            }
        }

      return safeNodes;

    }
   
   
};