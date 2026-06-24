class Solution {
public:
// aproach bfs ---> multi src
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
    //<--  --> left right
        for(int i=0;i<n;i++){

            if(board[i][0]=='O'){
                board[i][0]='S';
                q.push({i,0});
            }

            
            if(board[i][m-1]=='O'){
                board[i][m-1]='S';
                q.push({i,m-1});
            }
        }
    // ^ v up down
          for(int j=0;j<m;j++){

            if(board[0][j]=='O'){
                board[0][j]='S';
                q.push({0,j});
            }

            
            if(board[n-1][j]=='O'){
                board[n-1][j]='S';
                q.push({n-1,j});
            }
          
          }
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

            for(auto[x,y] : dir){
                int dx=i+x;
                int dy=j+y;
                
                 if(dx>=0 && dy>=0 && dx<n &&dy<m && board[dx][dy]=='O'){
                    board[dx][dy]='S';
                    q.push({dx,dy});
                 }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='S') board[i][j]='O';
            }
        }
    }
};