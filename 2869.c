int minOperations(int* nums, int numsSize, int k) {
    long mask = 1;
    int res = 0;
    mask = (mask << k) - 1;
    for(int i = numsSize - 1; i >= 0; i--){
        long temp = 1;
        temp <<= (nums[i] - 1);
        mask &= ~temp;
        res++;
        if(!mask) return res;
    }
    return 0;
}