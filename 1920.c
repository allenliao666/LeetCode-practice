int* buildArray(int* nums, int numsSize, int* returnSize) {
    int *res = malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        res[i] = nums[nums[i]];
    }
    
    *returnSize = numsSize;
    return res;
}