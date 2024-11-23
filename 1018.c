bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool *res = (bool *)malloc(numsSize * sizeof(bool));
    int now = 0;
    for(int i = 0; i < numsSize; i++){
        now <<= 1;
        now |= nums[i];
        now %= 5;
        res[i] = (now == 0) ? true : false;
    }
    *returnSize = numsSize;
    return res;
}

// bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
//     bool *res = (bool *)malloc(numsSize * sizeof(bool));
//     int now = 0;
//     for(int i = 0; i < numsSize; i++){
//         now <<= 1;
//         now |= nums[i];
//         now %= 10;
//         if(now == 5 || now == 0) res[i] = true;
//         else res[i] = false;
//     }
//     *returnSize = numsSize;
//     return res;
// }