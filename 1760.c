int canSplit(int *nums, int numsSize, int perBag, int maxOperations){
    int operations = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > perBag) operations += (nums[i] - 1)/perBag;
        if(operations > maxOperations) return 0;
    }
    return 1;
}

int minimumSize(int* nums, int numsSize, int maxOperations) {
    int size = 0;
    for(int i = 0; i < numsSize; i++){
        if(size < nums[i]) size = nums[i];
    }
    int l = 1, r = size, ans = size;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(canSplit(nums, numsSize, mid, maxOperations)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    return ans;
}

// int minimumSize(int* nums, int numsSize, int maxOperations) {
//     int size = 1;
//     while(1){
//         int cnt = 0;
//         for(int i = 0; i < numsSize; i++){
//             int temp = nums[i];
//             while(temp > size){
//                 temp -= size;
//                 cnt++;
//                 if(cnt > maxOperations) {
//                     break;
//                 }
//             }        
//         }
//         if(cnt <= maxOperations){ 
//             return size;
//         }
//         size++;
//     }
//     return -1;
// }