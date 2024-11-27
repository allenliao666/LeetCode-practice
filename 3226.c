int minChanges(int n, int k) {
    n ^= k;
    int set = __builtin_popcount(n);
    while(n){
        int move = __builtin_ctz(n);
        n >>= move;
        k >>= move;
        if(k & 0b1) return -1;
        n--;
    }
    return set;
}