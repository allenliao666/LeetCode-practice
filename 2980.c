bool hasTrailingZeros(int* nums, int numsSize) {
    int cnt = 0;
    for(int i = 0; i < numsSize; i++){
        if(!(nums[i] & 0b1)) cnt++;
        if(cnt == 2) return true;
    }
    return false;
}