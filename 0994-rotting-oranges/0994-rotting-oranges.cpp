class Solution {
public:
    queue<pair<int,int>> q;
    void check(vector<vector<int>> & grid,int i,int j,int n, int m){

        vector<pair<int,int>> ways={{i+1,j},{i,j+1},{i-1,j},{i,j-1}};

        for( auto dir : ways){
            if(dir.first < 0 || dir.second <0 || dir.first >=n || dir.second >=m) continue;
            if(grid[dir.first][dir.second]==1){
                q.push(dir);
                grid[dir.first][dir.second] =2;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0 ;i<n ;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   q.push({i,j});
                }
                if(grid[i][j]==1) count++;
            }
        }
        if(q.empty() && count == 0) return 0 ;
        int min=-1;
        while(!q.empty()){
            int size=q.size();

            for(int i=0 ; i<size;i++){
                auto u = q.front();
                q.pop();
                check(grid,u.first,u.second,n,m);
            }

            min++;
        }
        
         for(int i=0 ;i<n ;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }
        
        return min;
    }
};