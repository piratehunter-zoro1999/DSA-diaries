class Solution {
public:
    
    void dfs(int src,vector<vector<int>> & isConnected,vector<bool>&vis){
        vis[src]=true;

        for(int j =0 ; j <isConnected.size();j++){
            if(isConnected[src][j] && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }
    }
        
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n,false);
         int count=0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                count++;
            }
        }
        return count;
    }
};