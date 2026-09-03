class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {

        int n = grid.size();
        
        
        vector<vector<int>> dp(n,vector<int> (n,0));

        dp[0][0]=grid[0][0];

        for(int i = 1 ;i<n;i++){
            
            //left
            dp[i][0]= dp[i-1][0]+grid[i][0];

            //middle

            for(int j =1;j<i;j++){
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+grid[i][j];
            }

            //right

            dp[i][i]=dp[i-1][i-1]+grid[i][i];
        }

        return *min_element(dp[n-1].begin(),dp[n-1].begin()+n);



    }
};