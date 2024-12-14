long long continuousSubarrays(int* nums, int numsSize){
    long long cnt = 0;
    int l = 0, r = 0, min = 0, max = 0;
    while(r < numsSize) {
        if(abs(nums[r]-nums[min])>2 || abs(nums[r]-nums[max])>2) {
            l = r; min = r; max = r;
            while(l>0 && abs(nums[r]-nums[l])<=2) {
                min = (nums[l]<nums[min]) ? l : min;
                max = (nums[l]>nums[max]) ? l : max;
                l--;
            }
            l++;
        }
        min = (nums[r]<nums[min]) ? r : min;
        max = (nums[r]>nums[max]) ? r : max;
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}