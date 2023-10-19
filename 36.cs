public class Solution 
{
    public bool IsValidSudoku(char[][] board) 
    {
        // Create arrays to track how many times a number occurs
        int[,] rows = new int[9, 9];
        int[,] columns = new int[9, 9];
        int[,] subBoxes = new int[9, 9];

        // Loop through board
        for (int y = 0; y < board.Length; y++) 
        {
            for (int x = 0; x < board[y].Length; x++)
            {
                // Skip empty cells
                if (board[y][x] == '.')
                {
                    continue;
                }

                // Get char as index
                int index = board[y][x] - '1';

                // Check if nunmber has occured in current row
                // more than once
                if (rows[y, index]++ == 1) 
                {
                    return false;
                }

                // Do the same for cols and sub-boxes
                if (columns[x, index]++ == 1)
                {
                    return false;
                }

                if (subBoxes[((y / 3) * 3) + (x / 3), index]++ == 1) 
                {
                    return false;
                }
            }
        }

        return true;
    }
}