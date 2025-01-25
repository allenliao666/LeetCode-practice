int cmp(const void *a, const void *b){
    int *arr1 = (int *)a;
    int *arr2 = (int *)b;
    return arr1[0] - arr2[0];
}

int cmp2(const void *a, const void *b){
    return *(int *)a - *(int *)b;
} 
int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    int *idx = (int *)malloc(numsSize * sizeof(int));
    int cpy[numsSize][2];

    //bind the value with original index
    for(int i = 0; i < numsSize; i++){
        cpy[i][0] = nums[i];
        cpy[i][1] = i;
    }

    //sort cpy with value
    qsort(cpy, numsSize, sizeof(cpy[0]), cmp);
    int *res = (int *)malloc(numsSize * sizeof(int));

    //partition array with size
    for(int i = 0; i < numsSize;){
        int size = 0;
        int base = cpy[i][0];
        //record the subgroup with its size
        while(i < numsSize && cpy[i][0] <= base + limit){
            idx[size++] = cpy[i][1];
            base = cpy[i][0];
            i++;
        }

        //sort idx with indice
        qsort(idx, size, sizeof(int), cmp2);

        //bind value with indice
        for(int j = 0, k = i - size; j < size; j++, k++){
            res[idx[j]] = cpy[k][0];
        }
    }
    *returnSize = numsSize;
    return res;
}