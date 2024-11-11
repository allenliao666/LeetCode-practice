int min(int a, int b){
    return (a > b) ? b : a;
}

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    //[1,2,3] 2 -> 1
    //[0,1,2] 3 -> 2
    int left = 0, right = 0, sum = 0, minL = INT_MAX;
    int *or = calloc(32, sizeof(int));
    while(right < numsSize){
        sum |= nums[right];
        int n = nums[right];
        for(int i = 0 ; i < 32;i++){
            if(n & 0b1) or[i]++;
            n >>= 1;
        }
        while(left <= right && sum >= k){
            minL = min(minL, right - left + 1);
            int temp = 0;
            for(int i = 0; i < 32; i++){
                if(nums[left] & 0b1) or[i]--;
                nums[left] >>= 1;
                if(or[i]) temp |= (1 << i);
            }
            sum = temp;
            left++;
        }
        right++;
    }
    return (minL == INT_MAX) ? -1: minL;
}