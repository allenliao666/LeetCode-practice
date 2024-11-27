int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int *res = malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 2){
            res[i] = -1;
            continue;
        } 
        int k = 1;
        while((k | k + 1) != nums[i]) k++;
        res[i] = k;
    }
    *returnSize = numsSize;
    return res;
}