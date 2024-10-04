// Brutal solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *res = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(target - nums[i] == nums[j]){
                res[0] = nums[i];
                res[1] = nums[j];
                return res;
            }
        }
    }
    return res;
}