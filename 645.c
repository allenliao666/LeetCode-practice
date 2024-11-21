int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *res = (int *)malloc(2 * sizeof(int));
    int dup;
    unsigned int x = 0, z;
    for(int i = 0; i < numsSize; i++)
        x ^= nums[i] ^ (i + 1);
       
    for(int i = 0; i < numsSize; i++){
        dup = abs(nums[i]);
        if(nums[dup - 1] < 0) break;
        nums[dup - 1] = 0 - nums[dup - 1];
    } 
    res[0] = dup;
    res[1] = x ^ dup;
    return res;
}

// use negative integers to find duplicated number
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *res = (int *)malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        int dup = abs(nums[i]);
        if(nums[dup - 1] < 0) res[0] = dup;
        nums[dup - 1] = -1 * abs(nums[dup - 1]);   
    } 
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0) res[1] = i + 1;
    } 
    return res;
}

// use an array to record numbers of each number called
// int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//     *returnSize = 2;
//     int *res = (int *)malloc(2 * sizeof(int));
//     int *cnt = (int *)calloc(numsSize , sizeof(int));
//     for(int i = 0; i < numsSize; i++){
//         cnt[nums[i] - 1]++;
//     }
//     for(int i = 0; i < numsSize; i++){
//         if(cnt[i] == 2) res[0] = i + 1;
//         else if(cnt[i] == 0) res[1] = i + 1;
//     } 
//     return res;
// }