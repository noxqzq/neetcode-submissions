class Solution {
public:
    int rows, cols;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();          // assign the MEMBER, not a new local
        cols = grid[0].size();
        int best = 0;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == 1)
                    best = max(best, dfs(grid, r, c));
        return best;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        return 1
            + dfs(grid, r - 1, c)
            + dfs(grid, r + 1, c)
            + dfs(grid, r, c - 1)
            + dfs(grid, r, c + 1);
    }
};