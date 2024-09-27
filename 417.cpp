class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        queue<pair<int, int>> pacificTraverse;
        queue<pair<int, int>> atlanticTraverse;

        // Add the edges facing the ocean to the traverse queues
        for (int i = 0; i < heights.size(); i++) {
            pacificTraverse.push({ 0, i });
            atlanticTraverse.push({ heights[0].size() - 1, i });
        }
        for (int i = 0; i < heights[0].size(); i++) {
            pacificTraverse.push({ i, 0 });
            atlanticTraverse.push({ i, heights.size() - 1 });
        }

        traverse(heights, pacificTraverse, pacific);
        traverse(heights, atlanticTraverse, atlantic);

        // Return union of pacific and atlantic sets
        vector<vector<int>> ret;
        for (int y = 0; y < heights.size(); y++) {
            for (int x = 0; x < heights[y].size(); x++) {
                if (pacific[y][x] && atlantic[y][x]) {
                    ret.push_back({ y, x });
                }
            }
        }
        return ret;
    }

private:
    void traverse(vector<vector<int>>& heights, queue<pair<int, int>>& queue, vector<vector<bool>>& traversed) {
        while (!queue.empty()) {
            int iterCount = queue.size();
            for (int i = 0; i < iterCount; i++) {
                pair<int, int> pos = queue.front();
                queue.pop();

                if (traversed[pos.second][pos.first]) {
                    // Ignore if we've already been here
                    continue;
                } else {
                    traversed[pos.second][pos.first] = true;
                }

                // Check other 4 directions
                insertIntoQueue(heights, queue, { pos.first, pos.second + 1 }, heights[pos.second][pos.first]);
                insertIntoQueue(heights, queue, { pos.first, pos.second - 1 }, heights[pos.second][pos.first]);
                insertIntoQueue(heights, queue, { pos.first + 1, pos.second }, heights[pos.second][pos.first]);
                insertIntoQueue(heights, queue, { pos.first - 1, pos.second }, heights[pos.second][pos.first]);
            }
        }
    }

    void insertIntoQueue(vector<vector<int>>& heights, queue<pair<int, int>>& queue, pair<int, int> pos, int lastHeight) {
        // Check OOB
        if (pos.second < 0 || pos.first < 0 || pos.second >= heights.size() || pos.first >= heights[pos.second].size()) {
            return;
        }

        // Check if water can flow
        if (heights[pos.second][pos.first] < lastHeight) {
            return;
        }

        // Add position to traversal queue
        queue.push(pos);
    }
};
