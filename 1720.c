int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    int * res = (int *)malloc((encodedSize + 1) * sizeof(int));
    res[0] = first;
    for(int i = 1; i < encodedSize + 1; i++)
        res[i] = res[i - 1] ^ encoded[i - 1];
    *returnSize = encodedSize + 1;
    return res;
}