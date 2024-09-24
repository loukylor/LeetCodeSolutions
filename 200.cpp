class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == '0') {
                    continue;
                }

                islandCount++;
                dfs(x, y, grid);
            }
        }

        return islandCount;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (y < 0 || y >= grid.size()) {
            return;
        } else if (x < 0 || x >= grid[y].size()) {
            return;
        } else if (grid[y][x] == '0') {
            return;
        }
        grid[y][x] = '0';

        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
    }
};