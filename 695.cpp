class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == 0) {
                    continue;
                }

                int currentArea = dfs(x, y, grid);
                maxArea = max(currentArea, maxArea);
            }
        }

        return maxArea;
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (y < 0 || y >= grid.size()) {
            return 0;
        } else if (x < 0 || x >= grid[y].size()) {
            return 0;
        } else if (grid[y][x] == 0) {
            return 0;
        }
        int area = 1;
        grid[y][x] = 0;

        area += dfs(x + 1, y, grid);
        area += dfs(x - 1, y, grid);
        area += dfs(x, y + 1, grid);
        area += dfs(x, y - 1, grid);

        return area;
    }
};