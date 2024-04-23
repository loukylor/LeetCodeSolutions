class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            board.push_back(string(n, '.'));
        }
        vector<vector<string>> res;
        backtrack(n, 0, board, res);

        return res;
    }

private:
    void backtrack(int queensLeft, int row, vector<string>& board, vector<vector<string>>& res) {
        if (queensLeft == 0) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (!canInsert(board, row, col)) {
                continue;
            }

            board[row][col] = 'Q';
            backtrack(queensLeft - 1, row + 1, board, res);
            board[row][col] = '.';
        }
    }

    bool canInsert(vector<string>& board, int row, int col) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
            if (i + row - col >= 0 && i + row - col < board.size() && board[i + row - col][i] == 'Q') {
                return false;
            }
            if (-i + row + col >= 0 && -i + row + col < board.size() && board[-i + row + col][i] == 'Q') {
                return false;
            }
        }
        return true;
    }
};