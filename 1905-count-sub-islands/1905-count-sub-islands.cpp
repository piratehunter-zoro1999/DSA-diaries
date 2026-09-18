class Solution {
public:

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int m,int n,bool &sub){

        if(i<0 || j<0 || i>=m || j>=n || grid2[i][j]==0) return;

        if(grid1[i][j] != grid2[i][j] ){
            sub=false;
        }

        grid2[i][j]=0;

        dfs(grid1,grid2,i,j+1,m,n,sub);
        dfs(grid1,grid2,i+1,j,m,n,sub);
        dfs(grid1,grid2,i-1,j,m,n,sub);
        dfs(grid1,grid2,i,j-1,m,n,sub);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid2[i][j]==1){
                    bool sub=true;
                    dfs(grid1,grid2,i,j,m,n,sub);

                    if(sub) count++;
                }
            }
        }

        return count;
    }
};