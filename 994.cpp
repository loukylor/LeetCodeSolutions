class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        queue<pair<int, int>> rottenOranges;
        int unrotted = 0;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == 1) {
                    unrotted++;
                } else if (grid[y][x] == 2) {
                    rottenOranges.push({ x, y });
                }
            }
        }

        while (!rottenOranges.empty() && unrotted > 0) {
            int iterCount = rottenOranges.size();
            for (int i = 0; i < iterCount; i++) {
                pair<int, int> coords = rottenOranges.front();
                rottenOranges.pop();

                addRottenOrange(rottenOranges, grid, unrotted, coords.first, coords.second + 1);
                addRottenOrange(rottenOranges, grid, unrotted, coords.first, coords.second - 1);
                addRottenOrange(rottenOranges, grid, unrotted, coords.first + 1, coords.second);
                addRottenOrange(rottenOranges, grid, unrotted, coords.first - 1, coords.second);
            }
            minute++;
            rottenOranges = rottenOranges;
        }

        return unrotted > 0 ? -1 : minute;
    }

private:
    void addRottenOrange(queue<pair<int, int>>& rottenOranges, vector<vector<int>>& grid, int& unrotted, int posX, int posY) {
        if (posY >= grid.size() || posY < 0) {
            return;
        } else if (posX >= grid[posY].size() || posX < 0) {
            return;
        }

        if (grid[posY][posX] != 1) {
            return;
        }

        rottenOranges.push({ posX, posY });
        grid[posY][posX] = 2;
        unrotted--;
    }
};