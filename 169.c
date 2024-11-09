//majority vote algorithm
int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int cnt = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == candidate) cnt++;
        else{
            if(cnt > 0) cnt--;
            else{
                candidate = nums[i];
                cnt++;
            }
        } 
    }
    return candidate;
}
//brute force
// int majorityElement(int* nums, int numsSize) {
//     int *tested = calloc(numsSize, sizeof(int));
//     int max = 0;
//     for(int i = 0 ; i < numsSize; i++){
//         int temp = 1;
//         if(!tested[i]) tested[i] = 1;
//         else continue;
//         for(int j = i + 1 ; j < numsSize; j++){
//             if(nums[i] == nums[j]){
//                 tested[j] = 1;
//                 temp++;
//             }
//         }
//         if(temp > numsSize/2) return nums[i];
//     }
//     return max;
// }