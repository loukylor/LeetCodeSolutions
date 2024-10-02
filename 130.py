class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
    
        n = len(board)
        m = len(board[0])

        for i in range(n):
            if board[i][0]:
                self.dfs(0, i, board)
            if board[i][m - 1]:
                self.dfs(m - 1, i, board)
        
        for i in range(len(board[0])):
            if board[0][i]:
                self.dfs(i, 0, board)
            if board[n - 1][i]:
                self.dfs(i, len(board) - 1, board)

        for y in range(n):
            for x in range(m):
                if board[y][x] == "O":
                    board[y][x] = "X"
                elif board[y][x] == "":
                    board[y][x] = "O"        

    def dfs(self, x, y, board):
        if (y >= len(board) or y < 0 \
                or x >= len(board[y]) or x < 0 
                or board[y][x] == "" or board[y][x] == "X"):
            return
        
        board[y][x] = ""
        
        self.dfs(x + 1, y, board)
        self.dfs(x - 1, y, board)
        self.dfs(x, y + 1, board)
        self.dfs(x, y - 1, board)
        