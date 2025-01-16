int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int idx = 0, res = 0;
    if(!(nums1Size%2) && !(nums2Size%2)) return 0;
    if(nums1Size%2){
        for(int i = 0; i < nums2Size; i++) res ^= nums2[i];
    }
    if(nums2Size%2){
        for(int i = 0; i < nums1Size; i++) res ^= nums1[i];
    }
    return res;
}

// int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//     int idx = 0, res = 0, size = nums1Size * nums2Size;
//     int *xor = malloc(size * sizeof(int));
//     for(int i = 0; i < nums1Size; i++){
//         for(int j = 0; j < nums2Size; j++){
//             xor[idx++] = nums1[i] ^ nums2[j];
//         }
//     }
//     for(int i = 0; i < size; i++){
//         res ^= xor[i];
//     }
//     return res;
// }