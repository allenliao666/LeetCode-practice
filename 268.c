//bitwise operation
int missingNumber(int* nums, int numsSize) {
    int missing = numsSize;
    for(int i = 0; i < numsSize; i++){
        missing ^= nums[i];
        missing ^= i;
    }
    return missing;
}

// calculate total and minus nums[i]
// int missingNumber(int* nums, int numsSize) {
//     int total = numsSize * (numsSize+1) / 2;
//     for(int i = 0; i < numsSize; i++){
//         total -= nums[i];
//     }
//     return total;
// }