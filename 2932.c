int maximumStrongPairXor(int* nums, int numsSize) {
    int max = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i; j < numsSize; j++){
            int temp;
            if(abs(nums[i] - nums[j]) <= fmin(nums[i], nums[j]))
                temp = nums[i] ^ nums[j];
            if(max < temp) max = temp;
        }
    }
    return max;
}