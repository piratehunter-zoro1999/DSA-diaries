class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& info,
             vector<vector<int>>& heights, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || info[i][j])
            return;

        info[i][j] = true;

        if (i + 1 < m && heights[i][j] <= heights[i + 1][j])
            dfs(i + 1, j, info, heights, m, n);
        if (i - 1 >= 0 && heights[i][j] <= heights[i - 1][j])
            dfs(i - 1, j, info, heights, m, n);
        if (j - 1 >= 0 && heights[i][j] <= heights[i][j - 1])
            dfs(i, j - 1, info, heights, m, n);
        if (j + 1 < n && heights[i][j] <= heights[i][j + 1])
            dfs(i, j + 1, info, heights, m, n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights[0].size();
        int m = heights.size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {

            dfs(i, 0, pacific, heights, m, n);

            dfs(i, n - 1, atlantic, heights, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, heights, m, n);
            dfs(m - 1, j, atlantic, heights, m, n);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};