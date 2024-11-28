int singleNumber(int* nums, int numsSize) {
    int one = 0, two = 0;
    for(int i = 0; i < numsSize; i++){
        one = (one ^ nums[i]) & (~two);
        two = (two ^ nums[i]) & (~one);
    }
    return one;
}

// int singleNumber(int* nums, int numsSize) {
//     long res = 0;
//     for(int i = 0; i < 32; i++){
//         int cnt = 0;
//         for(int j = 0; j < numsSize; j++)
//             if((nums[j] >> i) & 0b1) cnt++;
//         long unique = cnt % 3;
//         res |= ((unique) << i);
//     }
//     return res;
// }