class Solution {
public:
    
     bool isCycle(int src,vector<vector<int>> & graph, vector<bool> & rec,vector<int> &code){
          
    // code 0-unkown
    //      1-safe
    //      2-unsafe

          if(code[src]==1) return false;
          if(code[src]==2) return true;

         
          rec[src]= true;
        
          for(int v : graph[src]){
             if (rec[v]) { // cycle
                code[src]=2;
                rec[src]= false;
                return true;
            }else if(code[v]==0){ // recursion
                if(isCycle(v,graph,rec,code)){
                    code[src]=2;
                    rec[src]= false;
                    return true;
                }
            }else if(code[v]==2){
                code[src]=2;
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
        vector<bool> rec(n,false);
        vector<int> code(n,0);
        for(int i =0 ;i<n;i++){
            
            if(!isCycle(i,graph,rec,code)){
                  safeNodes.push_back(i);
            }
        }

      return safeNodes;

    }
   
   
};