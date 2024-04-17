class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[y].size(); x++) {
                if (checkIn(board, x, y, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool checkIn(vector<vector<char>>& board, int x, int y, string& word, int i) {
        if (i == word.size()) {
            return true;
        }

        if (y < 0 || y >= board.size() || x < 0 || x >= board[y].size()) {
            return false;
        }

        if (board[y][x] != word[i]) {
            return false;
        }

        board[y][x] = ~board[y][x];

        bool res = checkIn(board, x + 1, y, word, i + 1) 
            || checkIn(board, x - 1, y, word, i + 1) 
            || checkIn(board, x, y + 1, word, i + 1) 
            || checkIn(board, x, y - 1, word, i + 1);

        board[y][x] = ~board[y][x];
        return res;
    }
};