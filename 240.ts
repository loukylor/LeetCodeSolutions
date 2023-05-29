function searchMatrix(matrix: number[][], target: number): boolean {
    // Start at top right
    let posX = matrix[0].length - 1
    let posY = 0
    
    while (posX >= 0 && posY < matrix.length) {
        // If target is bigger than current, go down
        // If target is smaller than current, go left
        if (target > matrix[posY][posX]) {
            posY++
        } else if (target < matrix[posY][posX]) {
            posX--
        } else {
            return true
        }
    }
    
    // If it goes off the matrix, it's not in the matrix
    return false
};
