class Solution {
public:
void dfs(int i ,int j , vector<vector<char>> & board,int m,int n){

    if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='X'|| board[i][j]=='S') return;

    board[i][j]='S';

    dfs(i+1,j,board,m,n);
    dfs(i-1,j,board,m,n);
    dfs(i,j+1,board,m,n);
    dfs(i,j-1,board,m,n);

}
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n=board[0].size();

        for(int i=0 ;i<m ;i++){
            dfs(i,0,board,m,n);
            dfs(i,n-1,board,m,n);
        }
        for(int j=0 ;j<n ;j++){
            dfs(0,j,board,m,n);
            dfs(m-1,j,board,m,n);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='S'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};