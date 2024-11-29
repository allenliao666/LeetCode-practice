int* singleNumber(int* nums, int numsSize, int* returnSize) {
    long val = 0;
    for(int i = 0;i < numsSize; i++){
        val ^= nums[i];
    }
    int first = 0, second = 0;
    val &= -val;
    for(int i = 0; i < numsSize; i++){
        int temp = nums[i];
        if(temp & val) second ^= temp;
        else first ^= temp;
    }
    *returnSize = 2;
    int *res = (int *)malloc(*returnSize * sizeof(int));
    res[0] = first;
    res[1] = second;
    return res;
}