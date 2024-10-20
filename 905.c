/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int *res = (int *)malloc(numsSize * sizeof(int));
    int idx= 0;
    //store even number in res
    for(int i = 0; i < numsSize; i++){
        if(nums[i] % 2 == 0){
            res[idx] = nums[i];
            idx++;
        }
    }
    //store odd number in res after even number
    for(int i = 0; i < numsSize; i++){
        if(nums[i] % 2 != 0){
            res[idx] = nums[i];
            idx++;
        }
    }
    *returnSize = numsSize;
    return res;
}