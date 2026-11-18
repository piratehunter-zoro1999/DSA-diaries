class Solution {
public:
    
    void bfs(vector<vector<char>>& grid,int i,int j){
       queue<pair<int,int>> q;
         int m = grid.size();
        int n = grid[0].size();


        ;

        q.push({i,j});
        grid[i][j]='0';

        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){


         auto [x,y] = q.front();
         q.pop();

         for(auto [dx,dy] : dir){
            int nx =x+dx;
            int ny =y+dy;

            if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] =='0'){
                continue;
            }else{

            
                q.push({nx,ny});
                grid[nx][ny]='0';

            }
        
         }

        }
    }

    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return 0;
        
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