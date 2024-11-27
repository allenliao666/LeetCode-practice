int* evenOddBit(int n, int* returnSize) {
    int *res = malloc(2 * sizeof(int));
    res[0] = __builtin_popcount(n & 0x55555555);
    res[1] = __builtin_popcount(n & 0xaaaaaaaa); 
    *returnSize = 2;
    return res;
}