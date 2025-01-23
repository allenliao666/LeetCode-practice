int countServers(int** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = gridColSize[0];

    int *rowCnt = (int *)calloc(row, sizeof(int));
    int *colCnt = (int *)calloc(col, sizeof(int));
    // Count the number of servers in each row and column
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (grid[r][c] == 1) {
                rowCnt[r]++;
                colCnt[c]++;
            }
        }
    }

    int res = 0;

    // Count the servers that can communicate
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (grid[r][c] == 1 && (rowCnt[r] > 1 || colCnt[c] > 1)) {
                res++;
            }
        }
    }

    return res;
}