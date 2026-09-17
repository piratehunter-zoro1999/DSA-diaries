class Solution {
public:
    
    int dfs(vector<vector<int>> &grid,int i,int j,int m,int n,int &area){

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            return 0;
        }

        grid[i][j]=0;
        area+=1;

        dfs(grid,i+1,j,m,n,area);
        dfs(grid,i-1,j,m,n,area);
        dfs(grid,i,j+1,m,n,area);
        dfs(grid,i,j-1,m,n,area);

        return area;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int maxArea=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area=0;
                if(grid[i][j] == 1){
                   maxArea=max(maxArea,dfs(grid,i,j,m,n,area));
                }
            }
        }

        return maxArea;
    }
};