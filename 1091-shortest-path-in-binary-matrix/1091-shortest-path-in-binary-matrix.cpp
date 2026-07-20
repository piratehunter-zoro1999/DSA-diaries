class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n-1 == 0 && grid[0][0]==0) return 1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;

        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        int count=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
               auto pair=q.front();
               q.pop();
               int x= pair.first;
               int y= pair.second;
               for(auto &d :dir){
                  int u = x+d.first;
                  int v =y+d.second;
                
                
                
                  if(u>=0 && v>=0 && u<n && v<n && grid[u][v]==0){
                    if(u==n-1 && v==n-1){
                    return ++count;
                    }
                    q.push({u,v});
                    grid[u][v]=1;
                  }
               }
               
            }
            count ++;
        }
     return -1;
    }
};