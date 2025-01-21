long long gridGame(int** grid, int gridSize, int* gridColSize) {
    int cols = *gridColSize;
    long long res= 0, row1Sum = 0, row2Sum = 0;
    for(int i = 1; i < cols; i++){
        row1Sum += grid[0][i];
    }
    res = row1Sum;
    cols--;
    for(int i = 0; i < cols; i++){
        row1Sum -= grid[0][i + 1];
        row2Sum += grid[1][i];
        res = fmin(res, fmax(row1Sum, row2Sum));
    }
    return res;
}
