bool divideArray(int* nums, int numsSize) {
    int res[501];
    for(int i = 0; i < numsSize; i++)
        res[nums[i]] ^= 1;
    for(int i = 0; i < 501; i++)
        if(res[i]) return false;
    return true;
}