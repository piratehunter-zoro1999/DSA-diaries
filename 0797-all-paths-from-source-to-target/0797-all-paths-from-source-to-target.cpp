class Solution {
public:
    
    void dfs(int src ,vector<vector<int>> &graph ,vector<vector<int>> &ans,vector<int> &temp){
        
        if( src == graph.size()-1) {
            ans.push_back(temp);
            return;
        }
        

        for(int v : graph[src]){
            
                temp.push_back(v);
                dfs(v,graph,ans,temp);
                temp.pop_back();
            
        }

    
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

    
        vector<vector<int>>ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0,graph,ans,temp);

        return ans;
    }
};