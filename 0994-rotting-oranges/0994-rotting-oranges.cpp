class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        
        bool flag=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) flag=true;
            }
        }

        if(q.size()==0 && flag ) return -1;
        if(!flag) return 0;

        int count=-1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                vector<pair<int,int>> dir ={{x+1,y},{x-1,y},{x,y+1},{x,y-1}};
                for(auto d : dir){
                    if(d.first>=0 && d.first<m && d.second<n && d.second>=0){
                        if(grid[d.first][d.second]==1){
                            grid[d.first][d.second]=2;
                            q.push({d.first,d.second});
                        }
                    }
                }

            }
            count++;

        }

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }

        return count;
    }
};