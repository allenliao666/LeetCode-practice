int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int rows = isWaterSize;
    int cols = isWaterColSize[0];
    *returnSize = rows;
    *returnColumnSizes = isWaterColSize;
    int **res = isWater;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res[i][j] = !res[i][j] * 9999;
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 1; j < cols; j++){
            res[i][j] = fmin(res[i][j], res[i][j-1] + 1);
        }
    }
    for(int j = 0; j < cols; j++){
        for(int i = 1; i < rows; i++){
            res[i][j] = fmin(res[i][j], res[i-1][j] + 1);
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = cols - 2; j >= 0; j--){
            res[i][j] = fmin(res[i][j], res[i][j+1] + 1);
        }
    }
    for(int j = 0; j < cols; j++){
        for(int i = rows - 2; i >= 0; i--){
            res[i][j] = fmin(res[i][j], res[i+1][j] + 1);
        }
    }
    return res;
}