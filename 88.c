void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // nums2 is empty
    if(n == 0) return;
    int tail = nums1Size - 1;

    //compare biggest value of nums1 and nums2
    while(n > 0 && m > 0){
        if(nums2[n-1] >= nums1[m-1]){
            nums1[tail] = nums2[n-1];
            n--;
        }else{
            nums1[tail] = nums1[m-1];
            m--;
        }
        tail--;
    }

    //value of nums2 is less than minimum of num1, just store  
    while(n > 0){   
        nums1[tail] = nums2[n-1];
        n--;
        tail--;
    }
}