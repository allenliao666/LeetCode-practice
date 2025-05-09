int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int idx = 0;
    bool *dup = calloc(numsSize, sizeof(bool));
    int *res = malloc((numsSize/2) * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        if(dup[nums[i]-1] == true) res[idx++] = nums[i];
        else dup[nums[i]-1] = true;
    }
    free(dup);
    *returnSize = idx;
    return res;
}