int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    for(int i = 0; i < imageSize; i++){
        for(int j = 0; j < (*imageColSize + 1)/ 2; j++){
            int temp = image[i][j] ^ 1;
            image[i][j] = image[i][*imageColSize - j - 1] ^ 1;
            image[i][*imageColSize - j - 1] = temp;
        }
    }
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;

}

// int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
//     int **res = (int **)malloc(imageSize * sizeof(int *));
//     for (int i = 0; i < imageSize; i++) {
//         res[i] = (int *)malloc(*imageColSize * sizeof(int));
//     }

//     for (int i = 0; i < imageSize; i++) {
//         for (int j = 0; j < *imageColSize; j++) {
//             res[i][j] = image[i][*imageColSize - j - 1];
//             res[i][j] ^= 1;
//         }
//     }
//     *returnSize = imageSize;
//     *returnColumnSizes = imageColSize;
//     return res;
// }