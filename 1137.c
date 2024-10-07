int tribonacci(int n){
    int i0 = 0, i1= 1, i2 = 1, res = 0;
    if(n == 0 | n == 1) return n;
    if(n == 2) return 1;
    for(int i = 0; i < n-2; i++){
        res = i0 + i1 + i2;
        i0 = i1;
        i1 = i2;
        i2 = res;
    }
    return res;
}