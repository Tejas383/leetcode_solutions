class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        
        if (i > 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1);
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1); 
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};