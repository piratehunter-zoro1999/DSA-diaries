class Solution {
public:
    
    void dfs(int src ,vector<vector<int>> &graph ,vector<bool> &vis,vector<vector<int>> &ans,vector<int> &temp){
        
        if( src == graph.size()-1) {
            ans.push_back(temp);
            return;
        }
        vis[src]=true;

        for(int v : graph[src]){
            if(!vis[v]){
                temp.push_back(v);
                dfs(v,graph,vis,ans,temp);
                temp.pop_back();
            }
        }

        vis[src]=false;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n,false);
        vector<vector<int>>ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0,graph,vis,ans,temp);

        return ans;
    }
};