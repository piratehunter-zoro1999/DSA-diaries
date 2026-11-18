class Solution {
public:
    queue<pair<int,int>> q;
    void bfs(vector<vector<char>>& grid,int i,int j){

         int m = grid.size();
        int n = grid[0].size();


        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] =='0') return;

        q.push({i,j});
        grid[i][j]='0';

        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){


         auto [x,y] = q.front();
         q.pop();

         for(auto [dx,dy] : dir){
            bfs(grid,i+dx,j+dy);
         }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int count=0;

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};