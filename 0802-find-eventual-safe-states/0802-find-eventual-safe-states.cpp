class Solution {
public:
    
     bool isCycle(int src,vector<vector<int>> & graph,vector<bool>& vis, vector<bool> & rec,vector<int> &code){
          

          if(code[src]==1) return false;
          if(code[src]==2) return true;
          
          vis[src]= true;
          rec[src]= true;
        
          for(int v : graph[src]){
            if(!vis[v]){
                if(isCycle(v,graph,vis,rec,code)){
                    code[v]=2;
                    return true;
                }
            }else if (rec[v]) {
                code[v]=2;
                return true;
            }
          }
          code[src]=1;
          rec[src]= false;

          return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> safeNodes;
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        vector<int> code(n,0);
        for(int i =0 ;i<n;i++){
            
            if(!isCycle(i,graph,vis,rec,code)){
                  safeNodes.push_back(i);
            }
        }

      return safeNodes;

    }
   
   
};