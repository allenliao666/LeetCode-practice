// fast & slow pointers
int findDuplicate(int* nums, int numsSize) {
    int slow = nums[nums[0]], fast = nums[slow];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
// map solution
// int findDuplicate(int* nums, int numsSize) {
//     int map[100001] = {0};
//     for(int i = 0; i < numsSize; i++){
//         if(map[nums[i]]) return nums[i];
//         map[nums[i]]++;
//     }
//     return 0;
// }