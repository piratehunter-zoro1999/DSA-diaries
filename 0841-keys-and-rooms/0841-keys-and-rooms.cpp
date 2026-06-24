class Solution {
public:
    void dfs(vector<vector<int>> &rooms,vector<bool>&vis,int src){
        vis[src]=true;
        for(int v : rooms[src]){
              if(!vis[v]){
                dfs(rooms,vis,v);
              }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
         
       dfs(rooms,vis,0);

       for(bool check : vis){
        if(check==false) return false;
       }
      return true;
    }
};