int maximumBeauty(int *nums, int numsSize, int k){
    int maxVal = 0;
    for(int i = 0; i < numsSize; i++){
        maxVal = nums[i] > maxVal ? nums[i] : maxVal;
    }
    int bufSize = maxVal + 10;
    int *buf = calloc(bufSize, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        int l = nums[i] - k > 0 ? nums[i] - k : 0;
        int r = nums[i] + k > maxVal ? maxVal + 1 : nums[i] + k + 1;
        buf[l]++;
        if(r < bufSize) buf[r]--; 
    }
    int max = buf[0];
    for(int i = 1; i < bufSize; i++){
        buf[i]+=buf[i - 1];
        max = buf[i] > max ? buf[i] : max;
    }
    free(buf);
    return max;
}

// int cpr(const void *a, const void *b){
//     return(*(int *)a - *(int *)b);
// }
// int maximumBeauty(int *nums, int numsSize, int k){
//     qsort(nums, numsSize, sizeof(int), cpr);
//     int l = 0, max = 0;
//     for(int r = 0; r < numsSize; r++){
//         while(nums[r] - nums[l] > 2 * k) l++;
//         max = r - l + 1 > max ? r - l + 1 : max ;
//     }
//     return max;
// }
