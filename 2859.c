int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    int res = 0;
    for(int i = 0; i < fmin(1024, numsSize); i++){
        if(__builtin_popcount(i) == k && i < numsSize) res += nums[i];
    }
    return res;
}