int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *res = calloc(ASize, sizeof(int));
    long aMap = 0, bMap = 0, temp = 0;
    for(int i = 0; i < ASize; i++){
        aMap |= ((long)1 << A[i]);
        bMap |= ((long)1 << B[i]);
        temp = __builtin_popcountl(aMap & bMap);
        res[i] = temp;
    }
    *returnSize = ASize;
    return res;
}

// int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
//     int *res = calloc(ASize, sizeof(int));
//     int *cnt = calloc(ASize + 1, sizeof(int));
//     int conPre = 0;
//     for(int i = 0; i < ASize; i++){
//         cnt[A[i]]++;
//         cnt[B[i]]++;
//         if(cnt[A[i]] == 2) conPre++;
//         if(cnt[B[i]] == 2 && A[i] != B[i]) conPre++;
//         res[i] = conPre;
//     }
//     *returnSize = ASize;
//     return res;
// }