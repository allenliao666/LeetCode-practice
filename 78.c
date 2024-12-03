int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize;
    *returnSize = total;
    *returnColumnSizes = malloc(total * sizeof(int));
    int **res = (int **)malloc(total * sizeof(int *));
    res[0] = NULL;
    (*returnColumnSizes)[0] = 0;
    for(int i = 1; i < total; i++){
        int cnt = __builtin_popcount(i);
        (*returnColumnSizes)[i] = cnt;
        res[i] = malloc(cnt * sizeof(int));
        int idx = 0, temp = i, bit = 0;
        while(temp){
            if(temp & 0b1){
                res[i][idx] = nums[bit];
                idx++;
            }
            temp >>= 1;
            bit++;
        }
    }
    return res;
}