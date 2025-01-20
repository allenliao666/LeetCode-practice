int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
    int rows = matSize, cols = matColSize[0];
    int *order = (int *) calloc((arrSize + 1), sizeof(int));
    int res = INT_MAX;
    for(int i = 0; i < arrSize; i++){
        order[arr[i]] = i;
    }
    for(int i = 0; i < rows; i++){
        int least = 0;
        for(int j = 0; j < cols; j++){
            int temp = order[mat[i][j]];
            least = temp > least ? temp : least;
        }
        res = least < res ? least : res;
    }
    for(int j = 0; j < cols; j++){
        int least = 0;
        for(int i = 0; i < rows; i++){
            int temp = order[mat[i][j]];
            least = temp > least ? temp : least;
        }
        res = least < res ? least : res;
    }
    return res;
}