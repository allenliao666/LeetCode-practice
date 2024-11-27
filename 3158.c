int duplicateNumbersXOR(int* nums, int numsSize) {
    uint64_t set = 0;
    int res = 0;
    for(int i = 0; i < numsSize; i++){
        if((set >> nums[i]) & 0b1) res ^= nums[i];
        else set |= ((uint64_t)0b1 << nums[i]);
    }
    return res;
}

// int duplicateNumbersXOR(int* nums, int numsSize) {
//     int map[51] = {0}, res = 0;
//     for(int i = 0; i < numsSize; i++){
//         map[nums[i]]++;
//         if(map[nums[i]] == 2) res ^= nums[i];
//     }
//     return res;
// }