char* toHex(int num) {
    char *res = (char *) malloc(9 * sizeof(char));
    res[8] = '\0';
    int i = 7;
    unsigned int x = num;
    for(;i >= 0; i--){
        int temp = x & 0b1111;
        if(15 >= temp && temp> 9) res[i] = temp + 'W';
        else res[i] = temp + '0';
        x >>= 4;
        if(x == 0) break; 
    } 
    return &res[i];
}