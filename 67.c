char* addBinary(char* a, char* b) {
    int aL = strlen(a), bL = strlen(b);
    int  resL = fmax(aL, bL) + 2;
    int temp = 0;
    char *res = (char*) malloc(resL * sizeof(char));

    res[--resL] = '\0';
    aL--; bL--;
    while(--resL >= 0){
        //string to int
        temp += (aL >= 0) ? a[aL--] - '0' : 0;
        temp += (bL >= 0) ? b[bL--] - '0' : 0;
        //int to string
        res[resL] = temp % 2 + '0';
        temp /= 2; 
    }
    if(res[0] == '0') return res[1];
    return res;
}