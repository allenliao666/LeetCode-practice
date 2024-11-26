//recursive solution
int xorSum(int *nums, int numsSize, int level, int current){
    if(level == numsSize) return current;
    int include = xorSum(nums, numsSize, level + 1, current ^ nums[level]);
    int exclude = xorSum(nums, numsSize, level + 1, current);
    return include + exclude;
}

int subsetXORSum(int* nums, int numsSize) {
    return xorSum(nums, numsSize, 0, 0);
}

// int subsetXORSum(int* nums, int numsSize) {
//     int res = 0;
//     for(int i = 0; i < (1 << numsSize); i++){
//         int xor = 0;
//         for(int j = 0; j < numsSize; j++){
//             if((i >> j) & 1) xor ^= nums[j];
//         }
//         res += xor;
//     }
//     return res;
// }