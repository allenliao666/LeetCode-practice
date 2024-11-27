int findKOr(int* nums, int numsSize, int k) {
    int res = 0;
    for(int i = 0; i < 31; i++){
        int temp = 0;
        for(int j = 0; j < numsSize; j++){
            if(nums[j] & (0b1 << i)) temp ++;
            if(temp >= k) {
                res |= (0b1 << i);        
                break;
            }
        }
    }
    return res;
}